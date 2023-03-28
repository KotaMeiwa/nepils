# nepils
**Ne**o**Pi**xel **L**ibrary for **S**presense, it's supplement for adafruit / Adafruit_NeoPixel.

(I think) adafruit / Adafruit_NeoPixel is most famous library to controll NeoPixel LED strup on Arduino platform. But as of Mar/2023 it doesn't work with Sony Spresense platform.

Main class in this library, *Adafruit_NeoPixel_Spresense* is inherited class *Adafruit_NeoPixel* in adafruit / Adafruit_NeoPixel therefore *Adafruit_NeoPixel_Spresense* has same methods as *Adafruit_NeoPixel* (some methods are not supported).

## Version history
| Version # | Release date  | Changes                                       |
| ---        | ---         | ---                                            |
| Ver. 0.1.0     | 2023-03-xx  | First release                              |

## Installation
**This library requires adafruit / Adafruit_NeoPixel.**

First of all installation of adafruit / Adafruit_NeoPixel
1. Go to the Releases page.
1. Download [the latest release](https://github.com/adafruit/Adafruit_NeoPixel/releases) (select ZIP type package).
1. In the Arduino IDE, go to the menu "Sketch > Include Library > Add .ZIP Library"

Next, installation of this library. Same operation of above installation.
1. Go to the Releases page.
1. Download [the latest release](https://github.com/KotaMeiwa/nepils/releases) (select ZIP type package).
1. In the Arduino IDE, go to the menu "Sketch > Include Library > Add .ZIP Library"

## API

## Supported Arduino board
[Sony Spresense](https://developer.sony.com/develop/spresense/)

As for other Arduino board, use just [adafruit / Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel).

## License
This software is distributed under MIT license, in detail see also [LICENSE](/LICENSE).

## Copyright
Copyright 2023 Kota Meiwa

To implement the following methods, [hideakitai/SpresenseNeoPixel](https://github.com/hideakitai/SpresenseNeoPixel) (under MIT license, Copyright (c) 2019 Hideaki Tai) was great reference and some portion of the source code is active in the following methods. I'm grateful to meet amazing library!
- void Adafruit_NeoPixel_Spresense::begin(void);  
- void Adafruit_NeoPixel_Spresense::show(void);
- void Adafruit_NeoPixel_Spresense::write_bit_off()
- void Adafruit_NeoPixel_Spresense::write_bit_on()
- void Adafruit_NeoPixel_Spresense::write(uint8_t value)
- void Adafruit_NeoPixel_Spresense::wait_cycles(uint32_t n)
