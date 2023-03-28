// SPDX-FileCopyrightText: 2023 Kota Meiwa
// SPDX-License-Identifier: MIT

#include <Arduino.h>
#include <Adafruit_NeoPixel_Spresense.h>

///////////////////////
Adafruit_NeoPixel_Spresense::Adafruit_NeoPixel_Spresense(uint16_t led_num, int16_t pin_no = 6)
:   Adafruit_NeoPixel(led_num, pin_no),
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
    m_reg_val = *m_reg_addr;

    clear();
    begun = true;
}

///////////////////////
void Adafruit_NeoPixel_Spresense::show(void)
{
    while(!canShow()){}

    const uint8_t pixel_size = get_pixel_size();
    if (pixel_size==3){
        noInterrupts();
        
        for (uint32_t pixel_ind = 0; pixel_ind < Adafruit_NeoPixel::numLEDs; ++pixel_ind){
            write(LOW);
            wait_cycles(m_wait_cycles_reset);
            
            uint8_t* pixel_pt = Adafruit_NeoPixel::pixels + (pixel_ind * pixel_size);
            for(uint8_t rgb = 0; rgb < pixel_size; ++rgb){
                //Don't use for-loop with 8 times.    Timing of data sending is corrupt.
                uint8_t pix_comp_val = min(pixel_pt[rgb], m_rgb_max);
                (pix_comp_val & 0x80) ? write_bit_on() : write_bit_off();
                (pix_comp_val & 0x40) ? write_bit_on() : write_bit_off();
                (pix_comp_val & 0x20) ? write_bit_on() : write_bit_off();
                (pix_comp_val & 0x10) ? write_bit_on() : write_bit_off();
                (pix_comp_val & 0x08) ? write_bit_on() : write_bit_off();
                (pix_comp_val & 0x04) ? write_bit_on() : write_bit_off();
                (pix_comp_val & 0x02) ? write_bit_on() : write_bit_off();
                (pix_comp_val & 0x01) ? write_bit_on() : write_bit_off();
            }
        }
        
        interrupts();
    }
}

