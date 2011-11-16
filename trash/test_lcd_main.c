
//*****************************************************************************
//
// Work File    : main.c
// Description	: Test module for KS0107 driven LCD display
// Author	: Sami Varjo
// Created	: 2008-06-23
// Revised	: 2008-06-28
// Version	: 0.2
// Target MCU	: Atmel AVR series - ATMEGA 5815 (or equivalent);
//
// This code is distributed under the GNU Public License
// which can be found at http://www.gnu.org/licenses/gpl.txt
//
//*****************************************************************************
#ifndef F_CPU
//#define F_CPU 1000000UL  //CPU speed 1Mhz (for delay.h)
#define F_CPU  7372800UL   //Atmega5815 8PU  7.3728MHz
//#define F_CPU 14745600UL //Atmega8    14.7456MHz
#endif

#include <util/delay.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "lcd_driver_KS0107.h"
#include "lcd_graphics.h"
#include "girl_1_glcd.h"
#include "atmel_glcd.h"

//#include "arial_bold_14.h"
#include "corsiva_12.h"

void wait_100x_ms(int ms) { uint8_t i; for (i=0;i<ms;i++) _delay_ms(100); }
void drawTest(int type);

int main(void)
{
  LCD_init();
  
  while(1) {    
    drawTest(0); //simple text    
    drawTest(1); //simple drawing
    drawTest(2); //more simple drawing
    drawTest(6); //simple progress bar
    drawTest(3); //scrolling text up-down
    drawTest(4); //menus with invert
    drawTest(5); //reading status of LCD
    drawTest(7); //128x64 bmp on screen   
    drawTest(8); //put a bmp on screen (atmel picture is 108x35)    
    drawTest(9);
  }  
  return 0;
}

void drawTest(int type){
  uint8_t i,j;
  
  uint8_t menuStrings[5][8] = {"Menu1\0","Menu2\0","Menu3\0","Menu4\0","Menu5\0"};
  
  switch (type){

  case 0: //simple text on screen
    LCD_clr();
    LCD_setCursorXY(15,0);
    LCD_puts ((uint8_t*)"Hello AVR world!\0");
    LCD_putsp((uint8_t*)"This LCD uses KS0107\0",3,3);
    LCD_putsp((uint8_t*)"Too long paged text is wrapped automatically\0",5,3);
    wait_100x_ms(30);
    break;

  case 1: //some of the drawing functions
    LCD_clr();
    LCD_drawLine(0,0,127,63);
    LCD_drawLine(0,63,127,0);
    LCD_drawRect(10,10,117,53);
    LCD_fillCirc(63,31,15);
    wait_100x_ms(20);

    break;

  case 2: //write on screen byte by byte
     for(j=0;j<8;j++){
	LCD_setCursorXY(0,j*8);
	for(i=0;i<LCD_LINE_LENGTH/4;i++){	  
	  LCD_writeByte(0b00110011);
	  LCD_writeByte(0b00110011);
	  LCD_writeByte(0b11001100);
	  LCD_writeByte(0b11001100);
	}
     }
    wait_100x_ms(20);
    break;

  case 3: //scrolling text up->down
    LCD_clr();
    LCD_setCursorXY(0,0);
    LCD_puts((uint8_t*)"Scrolling text\n goes here..!\0");      
    i=63;
    j=110;
    while(j>0){
      _delay_ms(30);      
      LCD_selectLeftChip();
      LCD_setInitialLineAddress(i);
      LCD_selectRightChip();
      LCD_setInitialLineAddress(i);
      if (i==0) i=63;
      else i--;
      j--;
    }
    LCD_clr();
    LCD_selectLeftChip();
    LCD_setInitialLineAddress(0);
    LCD_selectRightChip();
    LCD_setInitialLineAddress(0);
    break;

  case 4:  //using invert for menus
    
    for(i=0;i<5;i++){
      LCD_putsp(menuStrings[i],i+1,25);
    }
    j=2;
    while(j--){
      LCD_invertPage(1,20,58);
      wait_100x_ms(3);
      for(i=0;i<5;i++){      
	wait_100x_ms(3);
	LCD_invertPage(i+1,20,58);
	if(i<4)
	  LCD_invertPage(i+2,20,58);
	wait_100x_ms(3);
      }
    }
    break;

  case 5: //read status (on /off)
    j=4;
    while(j--){
      LCD_clr();
      if(!LCD_isOff()){
	LCD_putsp((uint8_t*)"LCD is On\0",1,10);
	wait_100x_ms(5);
	LCD_off();
      }
      else {
	wait_100x_ms(5);
	LCD_on();
	LCD_putsp((uint8_t*)"LCD was Off\0",1,10);
	wait_100x_ms(5);
      }
    }
    break;

  case 6: //"progress bar"
    LCD_clr();
    LCD_drawRect(5,5,122,58);
    LCD_putsp((uint8_t*)"Prosessing...\0",2,16);
    LCD_drawRect(10,30,113,41);

    for(j=0;j<100;j++){     
      LCD_setCursorXY(12+j,32);
      LCD_writeByte(0xff);
      wait_100x_ms(1); 
    }
    LCD_putsp((uint8_t*)"Done!        \0",2,16);
    wait_100x_ms(10);
    break;

  case 7:
    LCD_clr();
    LCD_drawFullBMP(girl_1_glcd_bmp);
    wait_100x_ms(20);
    break;

  case 8:
    i=0b10101010;
    LCD_clr();
    LCD_drawBMP((uint8_t*)atmel_glcd_bmp, 12, 12, 
		  ATMEL_GLCD_WIDTH,ATMEL_GLCD_HEIGHT);

    wait_100x_ms(20);
    break;

  case 9:
    LCD_clr();
    
    LCD_putgstr((uint8_t*)"Corsiva 12 test", Corsiva_12,10,10);
    LCD_putgstr((uint8_t*)"qwertyhjkl12345", Corsiva_12,12,30);
    
    //    LCD_putgstr((uint8_t*)"putgstr() test",Arial_Bold_14,10,10);
    //LCD_putgstr((uint8_t*)"1q2w3e4r5t6y8u9i0l",Arial_Bold_14,10,30);

    wait_100x_ms(20);
  }
}
