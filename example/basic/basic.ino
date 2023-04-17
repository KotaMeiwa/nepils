// SPDX-FileCopyrightText: 2023 Kota Meiwa
// SPDX-License-Identifier: MIT

#include <Adafruit_NeoPixel_Spresense.h>

const uint16_t NUM_PIXELS = 16;
const uint16_t PIN = 6;

Adafruit_NeoPixel_Spresense neopixel(NUM_PIXELS, PIN);

void setup()
{
	Serial.begin(115200);
	delay(1000);

	neopixel.begin();

	Serial.println("serial console start!");
}

void loop()
{
	//Blink
	neopixel.fill(Adafruit_NeoPixel::Color(16, 16, 0)); neopixel.show(), delay(500);
	neopixel.fill(Adafruit_NeoPixel::Color(16, 0, 0)); neopixel.show(), delay(500);
}
