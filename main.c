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
    uint8_t k = 0, i, step = 0;
    _asm bcf _WDTCON, 0 _endasm;
    INTCONbits.GIE = 0;
    
    init_io();
    lcd_init();    
    glcd_init(GLCD_MODE_ON);
    
    init_interrupt();
    step_report_init(100);
            
    for(i = 0; i < 128; i++) {
        glcd_plot(i, 0, GLCD_COLOR_WHITE);
    }
    for(i = 0; i < 64; i++) {
        glcd_plot(0, i, GLCD_COLOR_WHITE);
    }
    
    
    while(1) {
        k = 0xff;
        delay_ms(100);
        glcd_write_data_at(0, 0, 0, k);
        k = glcd_read_data_at(0, 0, 0);
        step_report_set(step++ % 100);
        delay_ms(100);
        glcd_write_data_at(0, 0, 0, k);
        step_report_set(step++ % 100);
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

