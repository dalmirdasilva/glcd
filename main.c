/**
 * Glcd project
 * 
 * main.c
 * 
 * @author  Dalmir da Silva <dalmirdasilva@gmail.com>
 */
 
#include <pic18f4550.h>
#include "fuses.h"
#include "main.h"
#include "interrupt.c"


void main() {
    uint8_t k = 0, i;
    _asm bcf _WDTCON, 0 _endasm;
    INTCONbits.GIE = 0;
    
    init_io();
    lcd_init();    
    glcd_init(GLCD_MODE_ON);
    glcd_buffered_init();
    init_interrupt();
    while(1) {
        delay_ms(100);
        for(i = 0; i < 128; i++) {
            
            //glcd_draw_circle(1, 2, 10, 0x3);
            glcd_plot(i, 0, GLCD_COLOR_WHITE);
        }
        for(i = 0; i < 64; i++) {
            glcd_plot(0, i, GLCD_COLOR_WHITE);
        }
        if(k == 0) {
            k = 0xf0;
            glcd_scroll(GLCD_CHIP_1, GLCD_SCROLL_DOWN, 2);
            glcd_scroll(GLCD_CHIP_2, GLCD_SCROLL_UP, 1);
        }
    }
}

void init_io() {
    TRISEbits.TRISE1 = 0;
}

/*
 * Interrupt initialization
 */
void init_interrupt() {
    
    // Prescalar reg 0
    T0CONbits.T0PS0 = 1;
    
    // Prescalar reg 1
    T0CONbits.T0PS1 = 1;
    
    // Prescalar reg 2, sets up the prescaler to 1:256
    T0CONbits.T0PS2 = 1;
    
    // Enables the prescaler
    T0CONbits.PSA = 0;
    
    // Set the clock source for internal oscillator
    T0CONbits.T0CS = 0;
    
    // Clear the interrupt flag
    INTCONbits.T0IF = 0;
    
    // Enable tmr0 interrupt
    INTCONbits.T0IE = 1;
    
    // Enable Global interrupts
    INTCONbits.GIE = 1;
}

