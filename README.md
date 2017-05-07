# PIC24F16KL401-Tutorial-1-Ports
This tutorial gives you a simple overview how to basically handle with the GPIO on the MCU PIC24F16KL401.
Attached main.c file provides a straightforward description of used registers inside the MCU for the handling of the GPIO pins.
For more details see the main file.
The configuration file (config.h) comprises setup for necessary internal peripherals, e.g internal oscillator, deployment of the pins for I2C, ICSP and so on.

## Description of the main.c 
* In this tutorial was connected LED diode to the pin RA4. 
* At the output RB4 was attached a button. 
* This program runs in a simple endless loop that check if the button was pressed. 
  When the button is pressed the LED is turned OFF. After releasing the button the LED is turned ON.


