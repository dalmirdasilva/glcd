#include <pic18f4550.h>
#include "fuses.h"
#include "main.h"
#include "interrupt.c"
int count = 0;

void main() {
    uint8_t i;
    _asm bcf _WDTCON, 0 _endasm;
    
    init_io();
    init_interrupt();
    lcd_init();    
    glcd_init(GLCD_MODE_ON);
        
    //glcd_plot(30, 30, 0);
    glcd_screen(GLCD_COLOR_WHITE);
    lcd_clear();
    delay_ms(1000);
    while(1) {
        lcd_put_string_at("while(1) {", 0, 0, 100);
        for(i = 0; i < 32; i++) {
            glcd_plot(i, 0, GLCD_COLOR_BLACK);
        }
        for(i = 0; i < 64; i++) {
            glcd_plot(0, i, GLCD_COLOR_BLACK);
        }
        delay_ms(100);
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

