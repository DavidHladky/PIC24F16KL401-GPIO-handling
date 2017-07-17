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
     *  0 - GPIO pin is set as output
     *  1 - GPIO pin is set as input
     * 
     *  PORTx - This register reads a content of a GPIO
     *  LATx - This register writes data to the specified GPIO 
     * 
     *  ANSx This register controls an analog input of desired GPIO
     *  0 - Digital input buffer is active - must be cleared if you want to use peripherals SPI, I2C, USART and etc...
     *  1 - Digital input buffer is not active (use for analog input)
     */
    TRISAbits.TRISA4 = 1;  // Pin RA4 is set as the input (Button)
    TRISBbits.TRISB4 = 0; // Pin RB4 is set as the output (LED diode)
    ANSBbits.ANSB15 = 0; // Analog input on RB4 off
    LATBbits.LATB4 = 1;  // Set RB4 to logical 1 - turn ON LED
    
    while(1) // Endless loop
    {
        if(!PORTAbits.RA4) // If is the button pressed, GPIO RA4 = 0
        {
            LATBbits.LATB4 = 0; // Set RB4 to 0 - Turn OFF LED diode
        }
        else // If the button is not pressed, GPIO RA4 = 1
        {
           LATBbits.LATB4 = 1;  // Set RB4 to 1 - Turn IN LED diode
        }       
    }
    return 0;
}
