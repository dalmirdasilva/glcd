/**
 * Fuses configurations for pic18f4550 using usb module.
 */ 

code char __at (__CONFIG1L) CONFIG1L = (
    // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1)
    (_USBPLL_CLOCK_SRC_FROM_96MHZ_PLL_2_1L) &
    
    // System Clock Postscaler Selection bits
    (_CPUDIV__OSC1_OSC2_SRC___1__96MHZ_PLL_SRC___2__1L) &
    
    // 96MHz PLL Prescaler Selection bits
    (_PLLDIV_DIVIDE_BY_5__20MHZ_INPUT__1L)
);

code char __at (__CONFIG1H) CONFIG1H = (
    // Oscillator 1H options
    (_OSC_HS__HS_PLL__USB_HS_1H) &
    
    // Fail-Safe Clock Monitor Enable
    (_FCMEN_OFF_1H) &
    
    // Internal External Switch Over Mode
    (_IESO_ON_1H)
);
                                    
code char __at (__CONFIG2L) CONFIG2L = (
    // USB Voltage Regulator 2L options
    (_VREGEN_ON_2L) &
    
    // Power Up Timer
    (_PUT_ON_2L) &
    
    // Brown Out Detect
    (_BODEN_OFF_2L) &
    
    // Brown Out Voltage
    (_BODENV_2_7V_2L)
);
                                      
code char __at (__CONFIG2H) CONFIG2H = (
    // Watchdog Timer
    (_WDT_DISABLED_CONTROLLED_2H) & 
    
    // Watchdog Postscaler
    (_WDTPS_1_32768_2H)
);
                                      
code char __at (__CONFIG3H) CONFIG3H = (
    // CCP2 Mux
    (_CCP2MUX_RC1_3H) &
    
    // PortB A/D Enable
    (_PBADEN_PORTB_4_0__CONFIGURED_AS_DIGITAL_I_O_ON_RESET_3H) &
    
    // Low Power Timer1 Osc enable
    (_LPT1OSC_OFF_3H) &
    
    // Master Clear Enable
    (_MCLRE_MCLR_ON_RE3_OFF_3H)
);

code char __at (__CONFIG4L) CONFIG4L = (
    // Stack Overflow Reset
    (_STVR_OFF_4L) &
    
    // Low Voltage Program
    (_LVP_OFF_4L) &
    
    // Dedicated In-Circuit Port {ICD/ICSP}
    (_ENICPORT_OFF_4L) &
    
    // Extended CPU Enable
    (_ENHCPU_OFF_4L) &
    
    // Background Debug
    (_BACKBUG_OFF_4L)
);

code char __at (__CONFIG5L) CONFIG5L = (
    // Code Protect 00800-01FFF
    (_CP_0_OFF_5L) &
    
    // Code Protect 02000-03FFF
    (_CP_1_OFF_5L) &
    
    // Code Protect 04000-05FFF
    (_CP_2_OFF_5L) &
    
    // Code Protect 06000-07FFF
    (_CP_3_OFF_5L)
);

code char __at (__CONFIG5H) CONFIG5H = (
    // Data EE Read Protect
    (_CPD_OFF_5H) &
    
    // Code Protect Boot
    (_CPB_OFF_5H)
);

code char __at (__CONFIG6L) CONFIG6L = (
    // Table Write Protect 00800-01FFF
    (_WRT_0_OFF_6L) &
    
    // Table Write Protect 02000-03FFF
    (_WRT_1_OFF_6L) &
    
    // Table Write Protect 04000-05FFF
    (_WRT_2_OFF_6L) &
    
    // Table Write Protect 06000-07FFF
    (_WRT_3_OFF_6L)
);
                                      
code char __at (__CONFIG6H) CONFIG6H = (
    // Data EE Write Protect
    (_WRTD_OFF_6H) &
    
    // Table Write Protect Boot
    (_WRTB_OFF_6H) &
    
    // Config. Write Protect
    (_WRTC_OFF_6H)
);

code char __at (__CONFIG7L) CONFIG7L = (
    // Table Read Protect 00800-01FFF
    (_EBTR_0_OFF_7L) &
    
    // Table Read Protect 02000-03FFF
    (_EBTR_1_OFF_7L) &
    
    // Table Read Protect 04000-05FFF
    (_EBTR_2_OFF_7L) &
    
    // Table Read Protect 06000-07FFF
    (_EBTR_3_OFF_7L)
);

code char __at (__CONFIG7H) CONFIG7H = (
    // Table Read Protect Boot
    (_EBTRB_OFF_7H)
);
