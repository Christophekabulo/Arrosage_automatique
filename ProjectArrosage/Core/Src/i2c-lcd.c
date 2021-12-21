/*
  Library:        lcd16x2 - Parallel 8/4 bits
  Written by:     Mohamed Yaqoob
  Date Written:   04/12/2017
  Updated:        26/06/2020
  Description:    This is a library for the standard 16X2 LCD display, for the STM32 MCUs based on HAL libraries.
                  It perfroms the basic Text/Number printing to your 16X2 LCD, in 8 bits and 4 bits modes of operation.
  References**:
                  This was written based on the open source Arduino LiquidCrystal library
                  and by referring to the DATASHEET of the LCD16X2, also with the help of
                  the following YouTube tutorials on LCD 16X2:
                  (1): 'RC Tractor Guy' YouTube tutorial on the following link:
                       https://www.youtube.com/watch?v=efi2nlsvbCI
                  (2): 'Explore Embedded' YouTube tutorial on the following link:
                       https://www.youtube.com/watch?v=YDJISiPUdA8
 * Copyright (C) 2017 - M.Yaqoob - MutexEmbedded
   This is a free software under the GNU license, you can redistribute it and/or modify it under the terms
   of the GNU General Public License version 3 as published by the Free Software Foundation.
   This software library is shared with public for educational purposes, without WARRANTY and Author is not liable for any damages caused directly
   or indirectly by this software, read more about this on the GNU General Public License.
*/

#include "i2c-lcd.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

void Delay(uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}
void lcd_delay(void)
{
 Delay(1000);
}

void lcd_cmd(char out_char)
{
 DRS_GPIO_Port->BSRR= DRS_Pin;

 DE_GPIO_Port->BSRR  = DE_Pin;
 D4_GPIO_Port->BSRR = D4_Pin;
 D5_GPIO_Port->BSRR = D5_Pin;
 D6_GPIO_Port->BSRR  = D6_Pin;
 D7_GPIO_Port->BSRR  = D7_Pin;
 D8_GPIO_Port->BSRR  = D8_Pin;

 lcd_delay();

 DE_GPIO_Port->ODR |= DE_Pin;

 if((out_char & 0x10)>>4) D4_GPIO_Port->BSRR = D4_Pin; else  D4_GPIO_Port->BSRR = (uint32_t)D4_Pin << 16;
 if((out_char & 0x20)>>5)D5_GPIO_Port->BSRR = D5_Pin; else  D5_GPIO_Port->BSRR = (uint32_t)D5_Pin << 16;
 if((out_char & 0x40)>>6)  D6_GPIO_Port->BSRR = D6_Pin; else  D6_GPIO_Port->BSRR = (uint32_t)D6_Pin << 16;
 if((out_char & 0x80)>>7) D7_GPIO_Port->BSRR = D7_Pin; else  D7_GPIO_Port->BSRR = (uint32_t)D7_Pin << 16;
 if((out_char & 0x80)>>8) D8_GPIO_Port->BSRR = D8_Pin; else  D8_GPIO_Port->BSRR = (uint32_t)D7_Pin << 16;

 lcd_delay();

 DE_GPIO_Port->BSRR  = DE_Pin;
 D4_GPIO_Port->BSRR = D4_Pin;
 D5_GPIO_Port->BSRR = D5_Pin;
 D6_GPIO_Port->BSRR  = D6_Pin;
 D7_GPIO_Port->BSRR  = D7_Pin;
 D8_GPIO_Port->BSRR  = D8_Pin;

 lcd_delay();

 DE_GPIO_Port->ODR |= DE_Pin;

 if((out_char & 0x10)>>4) D4_GPIO_Port->BSRR = D4_Pin; else  D4_GPIO_Port->BSRR = (uint32_t)D4_Pin << 16;
  if((out_char & 0x20)>>5)D5_GPIO_Port->BSRR = D5_Pin; else  D5_GPIO_Port->BSRR = (uint32_t)D5_Pin << 16;
  if((out_char & 0x40)>>6)  D6_GPIO_Port->BSRR = D6_Pin; else  D6_GPIO_Port->BSRR = (uint32_t)D6_Pin << 16;
  if((out_char & 0x80)>>7) D7_GPIO_Port->BSRR = D7_Pin; else  D7_GPIO_Port->BSRR = (uint32_t)D7_Pin << 16;
  if((out_char & 0x80)>>8) D8_GPIO_Port->BSRR = D8_Pin; else  D8_GPIO_Port->BSRR = (uint32_t)D7_Pin << 16;

 lcd_delay();

 DE_GPIO_Port->BSRR  = DE_Pin;
 D4_GPIO_Port->BSRR = D4_Pin;
 D5_GPIO_Port->BSRR = D5_Pin;
 D6_GPIO_Port->BSRR  = D6_Pin;
 D7_GPIO_Port->BSRR  = D7_Pin;
 D8_GPIO_Port->BSRR  = D8_Pin;
}

void lcd_char_cp(char out_char)
{
 DRS_GPIO_Port->ODR |= DRS_Pin;

 DE_GPIO_Port->BSRR  = DE_Pin;
 D4_GPIO_Port->BSRR = D4_Pin;
 D5_GPIO_Port->BSRR = D5_Pin;
 D6_GPIO_Port->BSRR  = D6_Pin;
 D7_GPIO_Port->BSRR  = D7_Pin;
 D8_GPIO_Port->BSRR  = D8_Pin;

 lcd_delay();

 DE_GPIO_Port->ODR |= DE_Pin;

 if((out_char & 0x10)>>4) D4_GPIO_Port->BSRR = D4_Pin; else  D4_GPIO_Port->BSRR = (uint32_t)D4_Pin << 16;
  if((out_char & 0x20)>>5)D5_GPIO_Port->BSRR = D5_Pin; else  D5_GPIO_Port->BSRR = (uint32_t)D5_Pin << 16;
  if((out_char & 0x40)>>6)  D6_GPIO_Port->BSRR = D6_Pin; else  D6_GPIO_Port->BSRR = (uint32_t)D6_Pin << 16;
  if((out_char & 0x80)>>7) D7_GPIO_Port->BSRR = D7_Pin; else  D7_GPIO_Port->BSRR = (uint32_t)D7_Pin << 16;
  if((out_char & 0x80)>>8) D8_GPIO_Port->BSRR = D8_Pin; else  D8_GPIO_Port->BSRR = (uint32_t)D7_Pin << 16;

 lcd_delay();

 DE_GPIO_Port->BSRR  = DE_Pin;
 D4_GPIO_Port->BSRR = D4_Pin;
 D5_GPIO_Port->BSRR = D5_Pin;
 D6_GPIO_Port->BSRR  = D6_Pin;
 D7_GPIO_Port->BSRR  = D7_Pin;
 D8_GPIO_Port->BSRR  = D8_Pin;

 lcd_delay();

 DE_GPIO_Port->ODR |= DE_Pin;

 if((out_char & 0x10)>>4) D4_GPIO_Port->BSRR = D4_Pin; else  D4_GPIO_Port->BSRR = (uint32_t)D4_Pin << 16;
  if((out_char & 0x20)>>5)D5_GPIO_Port->BSRR = D5_Pin; else  D5_GPIO_Port->BSRR = (uint32_t)D5_Pin << 16;
  if((out_char & 0x40)>>6)  D6_GPIO_Port->BSRR = D6_Pin; else  D6_GPIO_Port->BSRR = (uint32_t)D6_Pin << 16;
  if((out_char & 0x80)>>7) D7_GPIO_Port->BSRR = D7_Pin; else  D7_GPIO_Port->BSRR = (uint32_t)D7_Pin << 16;
  if((out_char & 0x80)>>8) D8_GPIO_Port->BSRR = D8_Pin; else  D8_GPIO_Port->BSRR = (uint32_t)D7_Pin << 16;

 lcd_delay();

 DE_GPIO_Port->BSRR  = DE_Pin;
 D4_GPIO_Port->BSRR = D4_Pin;
 D5_GPIO_Port->BSRR = D5_Pin;
 D6_GPIO_Port->BSRR  = D6_Pin;
 D7_GPIO_Port->BSRR  = D7_Pin;
 D8_GPIO_Port->BSRR  = D8_Pin;
}

void lcd_out_cp(char *out_char)
{
 while(*out_char)
 {
  lcd_delay();
  lcd_char_cp(*out_char++);
 }
 lcd_delay();
}


void lcd_init(char bits, char font, char lines)
{
    HAL_Delay(250);
 lcd_cmd(_RETURN_HOME);
    HAL_Delay(50);
    lcd_cmd(0x20 | bits | font | lines);
    HAL_Delay(50);
    lcd_cmd(_LCD_INIT);
    HAL_Delay(50);
    lcd_cmd(0x0E);
    HAL_Delay(50);
    lcd_cmd(0x0C);
    HAL_Delay(50);
    lcd_cmd(0x01);
    HAL_Delay(100);
}

void lcd_gotoxy(unsigned char row, unsigned char column)
{
 if(row == 1)
 {
  lcd_cmd(0x80 + (column - 1));
 }
 else if(row == 2)
 {
  lcd_cmd(0xC0 + (column - 1));
 }
}

void lcd_char(unsigned char row, unsigned char column, char out_char)
{
 lcd_gotoxy(row, column);
 lcd_char_cp(out_char);
}

void lcd_print(unsigned char row, unsigned char column, char *out_char)
{
 lcd_gotoxy(row, column);
 lcd_out_cp(out_char);
}
void lcd_clear(void) {

 lcd_cmd(_CLEAR);
    HAL_Delay(2);

}
void lcd_line1(void) {
 lcd_cmd(0x80);
}

void lcd_line2(void) {
 lcd_cmd(0xC0);
}
