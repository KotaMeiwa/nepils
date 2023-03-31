# nepils
**Ne**o**Pi**xel **L**ibrary for **S**presense, it's supplement library for [adafruit / Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel).

(I think) adafruit / Adafruit_NeoPixel is most famous library to control NeoPixel LED strap on Arduino platform. But as of Mar/2023 it doesn't work with Sony Spresense platform.

Main class in this library, *Adafruit_NeoPixel_Spresense* is inherited class of *Adafruit_NeoPixel* in adafruit / Adafruit_NeoPixel therefore *Adafruit_NeoPixel_Spresense* has same methods as *Adafruit_NeoPixel*.

## Version history
| Version #     | Release date  | Changes          |
| ---           | ---           | ---              |
| Ver. 0.1.0    | 2023-03-31    | First release    |

## Installation
### For HW connection
[Here](https://www.marutsu.co.jp/pc/static/large_order/WS2812B_0124) ( (c) Marutsuelec Co.,Ltd. All Rights Reserved. ) is good reference to understand HW connection.

Go to the site and see the section, "(2) Arduinoで制御する".
In summary connect 3 lines between Spresense and LED strap.

| LED strap    |  Spresense
| ----         | ---
| DIN (green)  | D6
| VCC (red)    | 5V
| GND (white)  | GND

**Important notes:** Take care power consumption of LEDs.  Go [Here](https://www.marutsu.co.jp/pc/static/large_order/WS2812B_0124) "カスケード接続するときは全体の消費電流に注意" and check power consumption in your usage environment. If much power consumption is needed, consider to prepare external power supply equipment and use it.    Original [data sheet](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf) is also good reference for this topic.

### For Arduino IDE
**This library requires adafruit / Adafruit_NeoPixel.**

First of all installation of adafruit / Adafruit_NeoPixel
1. Go to the Releases page.
1. Download [the latest release](https://github.com/adafruit/Adafruit_NeoPixel/releases) (select ZIP type package).
1. In the Arduino IDE, go to the menu "Sketch > Include Library > Add .ZIP Library"

Next, installation of this library. Same operation of above installation.
1. Go to the Releases page.
1. Download [the latest version](https://github.com/KotaMeiwa/nepils/tags) (select ZIP type package).
1. In the Arduino IDE, go to the menu "Sketch > Include Library > Add .ZIP Library"

## API
Main class in this library, *Adafruit_NeoPixel_Spresense* is inherited class of *Adafruit_NeoPixel* in adafruit / Adafruit_NeoPixel therefore *Adafruit_NeoPixel_Spresense* has same methods as *Adafruit_NeoPixel*.

additional API for *Adafruit_NeoPixel*

- *uint8_t get_rgb_upper()*
- *void set_rgb_upper(uint8_t rgb_max)*

the following API is disabled

- *void setPin(int16_t p)*
- *void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w)*
- *void updateLength(uint16_t n)*
- *void updateType(neoPixelType t)*

## Supported Arduino board
[Sony Spresense](https://developer.sony.com/develop/spresense/)

As for other Arduino board, use just [adafruit / Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel).

## License
This software is distributed under MIT license, in detail see also [LICENSE](/LICENSE).

## Copyright
Copyright (c) 2023 Kota Meiwa

To implement the following methods, [hideakitai/SpresenseNeoPixel](https://github.com/hideakitai/SpresenseNeoPixel) (under MIT license, Copyright (c) 2019 Hideaki Tai) was great reference and some portion of the source code is active in the following methods. I'm grateful to meet amazing library!
- void Adafruit_NeoPixel_Spresense::begin(void);  
- void Adafruit_NeoPixel_Spresense::show(void);
- void Adafruit_NeoPixel_Spresense::write_bit_off()
- void Adafruit_NeoPixel_Spresense::write_bit_on()
- void Adafruit_NeoPixel_Spresense::write(uint8_t value)
- void Adafruit_NeoPixel_Spresense::wait_cycles(uint32_t n)
