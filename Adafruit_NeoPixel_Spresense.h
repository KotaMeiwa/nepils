// SPDX-FileCopyrightText: 2023 Kota Meiwa
// SPDX-License-Identifier: MIT

#pragma once
#ifndef ADAFRUIT_NEOPIXEL_SPRESENSE_H
#define ADAFRUIT_NEOPIXEL_SPRESENSE_H
#include <Arduino.h>
#include "wiring_private.h"
#include <Adafruit_NeoPixel.h>

class Adafruit_NeoPixel_Spresense : public Adafruit_NeoPixel
{
private:
	volatile uint32_t* m_reg_addr;
	uint32_t m_reg_val;
	uint8_t m_rgb_max;
	const uint32_t m_wait_cycles_reset;

public:
	Adafruit_NeoPixel_Spresense(uint16_t led_num, int16_t pin_no = 6);
	~Adafruit_NeoPixel_Spresense(){}

	uint8_t get_rgb_upper() { return m_rgb_max; }
	void set_rgb_upper(uint8_t rgb_max) {  m_rgb_max = rgb_max; }

public: //overwritten super class's method
	void begin(void);  
	void show(void);

protected: //diabled super class's method
	void setPin(int16_t p){}
	void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w){}
	void updateLength(uint16_t n){}
	void updateType(neoPixelType t){}

protected:
	inline uint8_t get_pixel_size(){ return (wOffset == rOffset? 3: 4); }

	inline void write_bit_off(){
		const uint32_t wait_time[] = {1, 28};
		write(HIGH), wait_cycles(wait_time[0]);
		write(LOW), wait_cycles(wait_time[1]);
	}

	inline void write_bit_on(){
		const uint32_t wait_time[] = {28, 1};
		write(HIGH), wait_cycles(wait_time[0]);
		write(LOW), wait_cycles(wait_time[1]);
	}

	inline void write(uint8_t value){
		bitWrite(m_reg_val, GPIO_OUTPUT_SHIFT, value);
		*m_reg_addr = m_reg_val;
	}

	inline void wait_cycles(uint32_t n){ // 4 clocks per cycle
		asm volatile (
			"0:" "SUBS %[count], 1;"
			"BNE 0b;"
			: [count] "+r" (n)
		);
	}
};

#endif  //ADAFRUIT_NEOPIXEL_SPRESENSE_H
