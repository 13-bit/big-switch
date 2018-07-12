#include <WS2812FX.h>
#include <Bounce2.h>

#define LED_COUNT 5
#define LED_PIN PIN_D5
#define BUTTON_PIN PIN_B0

#define FX_NUM_MODES 5

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Bounce debouncer = Bounce();

struct ledFxMode {
  uint8_t mode;
  uint32_t color;
  uint16_t speed;
  uint8_t brightness;
};

uint8_t fxIndex = 0;
ledFxMode fxModes[FX_NUM_MODES] = {{FX_MODE_RAINBOW_CYCLE, 0x000000, 8192, 255},
                                  {FX_MODE_BREATH, 0xdd550c, 512, 255},
                                  {FX_MODE_COLOR_WIPE_RANDOM, 0x000000, 256, 25},
                                  {FX_MODE_FIREWORKS_RANDOM, 0x000000, 64, 25},
                                  {FX_MODE_STATIC, 0x000000, 0, 0}};

boolean isOn = true;

void changeMode() {
  fxIndex++;
  ledFxMode mode = fxModes[fxIndex % FX_NUM_MODES];

  ws2812fx.setSpeed(mode.speed);
  ws2812fx.setColor(mode.color);
  ws2812fx.setMode(mode.mode);
  ws2812fx.setBrightness(mode.brightness);
}

void setup() {
  ledFxMode mode = fxModes[fxIndex % FX_NUM_MODES];

  ws2812fx.init();
  ws2812fx.setBrightness(mode.brightness);
  ws2812fx.setSpeed(mode.speed);
  ws2812fx.setColor(mode.color);
  ws2812fx.setMode(mode.mode);
  ws2812fx.start();

  pinMode(BUTTON_PIN,INPUT_PULLUP);
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5);
}

void loop() {
  ws2812fx.service();

  debouncer.update();

  if (debouncer.fell()) {
    Serial.println("button pressed");

    changeMode();
  }
}
