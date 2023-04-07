// SPDX-FileCopyrightText: 2023 Kota Meiwa
// SPDX-License-Identifier: MIT

#include <Arduino.h>
#include <Adafruit_NeoPixel_Spresense.h>

///////////////////////
Adafruit_NeoPixel_Spresense::Adafruit_NeoPixel_Spresense(uint16_t led_num, int16_t pin_no = 6)
:	Adafruit_NeoPixel(led_num, pin_no),
	m_rgb_max(255),
	m_wait_cycles_reset(1)
{
}

///////////////////////
void Adafruit_NeoPixel_Spresense::begin(void)
{
	pinMode(getPin(), OUTPUT);
	digitalWrite(getPin(), LOW);
	analog_stop(getPin());

	m_reg_addr = (uint32_t*)get_gpio_regaddr(pin_convert(getPin()));
	m_reg_val_high = m_reg_val_low = *m_reg_addr;
	bitWrite(m_reg_val_high, GPIO_OUTPUT_SHIFT, HIGH);
	bitWrite(m_reg_val_low, GPIO_OUTPUT_SHIFT, LOW);

	clear();
	begun = true;
}

///////////////////////
void Adafruit_NeoPixel_Spresense::show(void)
{
	while(!canShow()){}

	const uint8_t pixel_size = get_pixel_size();
	if (pixel_size==3 && 0<Adafruit_NeoPixel::numLEDs && Adafruit_NeoPixel::pixels!=NULL){
		uint8_t* pixel_pt = Adafruit_NeoPixel::pixels;
		uint8_t* pixel_pt_end = pixel_pt + Adafruit_NeoPixel::numLEDs*pixel_size;
		uint g, r, b;

		noInterrupts();
		write(LOW);
		wait_cycles(m_wait_cycles_reset);
		
		do{
			g = min(*(pixel_pt++), m_rgb_max);
			(g & 0x80) ? write_bit_on() : write_bit_off();
			(g & 0x40) ? write_bit_on() : write_bit_off();
			(g & 0x20) ? write_bit_on() : write_bit_off();
			(g & 0x10) ? write_bit_on() : write_bit_off();
			(g & 0x08) ? write_bit_on() : write_bit_off();
			(g & 0x04) ? write_bit_on() : write_bit_off();
			(g & 0x02) ? write_bit_on() : write_bit_off();
			(g & 0x01) ? write_bit_on() : write_bit_off();

			r = min(*(pixel_pt++), m_rgb_max);
			(r & 0x80) ? write_bit_on() : write_bit_off();
			(r & 0x40) ? write_bit_on() : write_bit_off();
			(r & 0x20) ? write_bit_on() : write_bit_off();
			(r & 0x10) ? write_bit_on() : write_bit_off();
			(r & 0x08) ? write_bit_on() : write_bit_off();
			(r & 0x04) ? write_bit_on() : write_bit_off();
			(r & 0x02) ? write_bit_on() : write_bit_off();
			(r & 0x01) ? write_bit_on() : write_bit_off();

			b = min(*(pixel_pt++), m_rgb_max);
			(b & 0x80) ? write_bit_on() : write_bit_off();
			(b & 0x40) ? write_bit_on() : write_bit_off();
			(b & 0x20) ? write_bit_on() : write_bit_off();
			(b & 0x10) ? write_bit_on() : write_bit_off();
			(b & 0x08) ? write_bit_on() : write_bit_off();
			(b & 0x04) ? write_bit_on() : write_bit_off();
			(b & 0x02) ? write_bit_on() : write_bit_off();
			(b & 0x01) ? write_bit_on() : write_bit_off();
		}while(pixel_pt!=pixel_pt_end);

		interrupts();
	}
}

