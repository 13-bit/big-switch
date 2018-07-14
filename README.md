# big-switch

A simple PlatformIO/Arduino sketch for a Teensy 2.0-powered lamp base for the NovelKeys Big Switch.

# Dependencies

* [WS2812FX](https://github.com/kitesurfer1404/WS2812FX)
* [Bounce 2](https://github.com/thomasfredericks/Bounce2)

# Parts manifest

* 1x NovelKeys Big Switch
* 1x Teensy 2.0
* 4x WS2812 individually-addressable RGB LEDs
* 1x Big Switch case (see below)

# Connections

The WS2812 LEDs are connected to the Teensy as follows:

| WS2812        | Teensy        |
| ------------- | ------------- |
| VCC           | VCC           |
| GND           | GND           |
| DIN           | D5            |

The Big Switch is connected to the Teensy as follows:

| Big Switch    | Teensy        |
| ------------- | ------------- |
| SIGNAL        | B0            |
| GND           | GND           |

If you prefer to use different data pins you may do so -- just change the #define declarations in the code.

# Schematics

![Schematic](https://i.imgur.com/uJTtCLS.png)

![Breadboard](https://i.imgur.com/ETrxOiR.png)

# Case

I have provided the [design files for a 3D-printed case on Thingiverse](https://www.thingiverse.com/thing:3000220). The case is small enough to be printed on a [Monoprice Mini Delta](https://www.mpminidelta.com/start).
