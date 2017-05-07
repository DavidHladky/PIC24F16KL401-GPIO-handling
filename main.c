/*
 * File:   main.c
 * Author: David Hladky
 * Created on 5/7/2016
 * An example of the use of PORTS in the MCU PIC24F16KL401
 */

#include "xc.h"
#include "config.h" // The configuration file

int main(void) {
    /*  TRISx - This register sets the direction of the port
     *  0 - A pin is set as input
     *  1 - A pin is set as outpt 
     * 
     *  PORTx - This register reads a content of the port/pin
     *  LATx - This register writes a data to the port/pin 
     * 
     *  ANSx This register controls an analog input of desired ports
     *  0 - Digital input buffer is active - must be cleared if you want to use peripherals SPI, I2C, USART and etc...
     *  1 - Digital input buffer is not active (use for analog input)
     */
    TRISAbits.TRISA4 = 1;  // Pin RA4 is set as the output (LED Diode)
    TRISBbits.TRISB4 = 0; // Pin RB4 is set as the input (Button)
    ANSBbits.ANSB15 = 0; // Analog input on RB4 off
    LATBbits.LATB4 = 1;  // Set RB4 to logical 1
    
    while(1) // Endless loop
    {
        if(!PORTAbits.RA4) // If is the button pressed RA = 0
        {
            LATBbits.LATB4 = 0; // Set RB4 to 0
        }
        else // If is not the button pressed RA = 1
        {
           LATBbits.LATB4 = 1;  // Set RB4 to 1
        }       
    }
    return 0;
}
