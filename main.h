#include <delay.h>
#include <lcd.c>
#include <lcd_string.c>
#include <glcd.c>
#include <lcd_test.c>
#include <lcd_custom_char.c>

void init_io() {
    TRISEbits.TRISE1 = 0;
} 
