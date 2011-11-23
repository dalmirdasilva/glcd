/**
 * Glcd project
 * 
 * main.h
 * 
 * @author  Dalmir da Silva <dalmirdasilva@gmail.com>
 */

void itoh(unsigned char i, char buffer[3]) {
    char c;
    unsigned char n;
    n = (i >> 4) & 0x0f;
    if(n > 9) {
        c = 'A';
        n -= 10; 
    } else {
        c = '0';
    }
    buffer[0] = c + n;
    n = i & 0x0f;
    if(n > 9) {
        c = 'A';
        n -= 10; 
    } else {
        c = '0';
    }
    buffer[1] = c + n;
    buffer[2] = 0;
}

#include <delay.h>
#include <lcd.c>
#include <lcd_string.c>

#include <glcd.h>
#include <glcd_buffered.h>
#ifndef GLCD_GET_AT
    #define GLCD_GET_AT(chip, page, line)               glcd_buffered_get_at(chip, page, line)
#endif

#ifndef GLCD_SEND_AT
    #define GLCD_SEND_AT(chip, page, line, byte)        glcd_buffered_send_at(chip, page, line, byte)
#endif
#include <glcd.c>
#include <glcd_buffered.c>
#include <glcd_draw.c>

void init_io();
void init_interrupt();
