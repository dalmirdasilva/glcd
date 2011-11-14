#include <pic18f4550.h>
#include "fuses.h"
#include "main.h"

void main() {
    int8_t i = 0;
    char c = 'A';
    char custom_chars[] = {
        0x00, 0x00, 0x00, 0x04,
        0x00, 0x00, 0x00, 0x00,
        
        0x00, 0x00, 0x0e, 0x0a,
        0x0e, 0x00, 0x00, 0x00,
        
        0x00, 0x1f, 0x11, 0x11,
        0x11, 0x1f, 0x00, 0x00
    };
    _asm bcf _WDTCON, 0 _endasm;
    init_io();
    lcd_init();
    lcd_put_string("Initializing...", 100);
    glcd_init(GLCD_MODE_ON);
    delay_ms(100);
    lcd_put_string("\ndone.", 100);
    glcd_plot(10, 10, 1);
    glcd_plot(30, 30, 0);
    
    lcd_put_string("------", 100);
    lcd_clear();
    while(1) {
        lcd_put_string_at("glcd_screen(1);", 0, 0, 100);
        glcd_screen(1);
        delay_ms(2000);
        lcd_put_string_at("glcd_screen(0);", 0, 1, 100);
        glcd_screen(0);
        delay_ms(2000);
    }
}
