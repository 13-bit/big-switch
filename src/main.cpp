#include <WS2812FX.h>
#include <Bounce2.h>

#define LED_COUNT 5
#define LED_PIN PIN_D5
#define BUTTON_PIN PIN_B0

#define FX_NUM_MODES 4

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Bounce debouncer = Bounce();

unsigned int fx_index = 0;

unsigned int fx_modes[FX_NUM_MODES] = {FX_MODE_RAINBOW_CYCLE, FX_MODE_BREATH, FX_MODE_COLOR_WIPE_RANDOM, FX_MODE_FIRE_FLICKER};

boolean isOn = true;

void setup() {
  ws2812fx.init();
  ws2812fx.setBrightness(255);
  ws2812fx.setSpeed(8192);
  ws2812fx.setColor(0xdd550c);
  ws2812fx.setMode(fx_modes[fx_index % FX_NUM_MODES]);
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

    fx_index++;
    ws2812fx.setMode(fx_modes[fx_index % FX_NUM_MODES]);
  }
}
