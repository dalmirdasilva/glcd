/**
 * Glcd project
 * 
 * interrupt.h
 * 
 * Contains a simple interrupt handler for general purposes.
 * 
 * @author  Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __PIC_LEDCUBE_INTERRUPT_H
#define __PIC_LEDCUBE_INTERRUPT_H 1 

#include <signal.h>

DEF_INTHIGH(high_interrupt_vector)
    DEF_HANDLER(SIG_TMR0, timer_0_handler)
END_DEF

uint8_t ps = 0xff;

/*
 * Multiplexer/framebuffer routine
 * 
 * This function is called by an interrupt generated by timer 0.
 */
SIGHANDLER(timer_0_handler) {
  
    // Clear interrupt flag
    INTCONbits.T0IF = 0;
    
    // Disable ie while commiting
    INTCONbits.GIE = 0;
    
    if(--ps == 0) {
        ps = 0x1f;

        // Commits the buffer into the glcd module
        glcd_buffered_commit();
    }
    
    // Enable after commit
    INTCONbits.GIE = 1;
}

#endif // __PIC_LEDCUBE_INTERRUPT_H

