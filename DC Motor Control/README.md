# DC Motor Control

## DC Motor Control Program

A DC motor control program is a software program designed to control the operation of a DC motor. The main purpose of the program is to manage the speed and direction of the motor based on the input signals received from sensors or other devices.

The program typically includes algorithms for speed and position control, as well as feedback mechanisms to ensure that the motor is operating as desired. It may also incorporate safety features such as current limiting or fault detection.

DC motor control programs can be used in a variety of applications, such as robotics, automation, and electric vehicles. They can be programmed using a variety of programming languages, including C, C++, Python, and MATLAB.

Overall, the main goal of a DC motor control program is to provide precise and reliable control of a DC motor, enabling it to perform a specific task efficiently and effectively.

The program included here is one of the simple illustrations for the above mentioned applications in C Language.

## About the included example

A C program for controlling two sets of pins on a microcontroller board as outputs in a loop. Here's an explanation of the code:

The #include <lpc17xx.h> statement is used to include the header file for the LPC17xx series of microcontrollers.

The delay_ms() function is used to provide a software delay in milliseconds. It takes an integer argument representing the delay time in milliseconds.

In the main() function, SystemInit() is called to initialize the system clock and PLL configuration.

LPC_PINCON->PINSEL4 = 0x000000 is used to configure the PORT2 pins as GPIO.

LPC_GPIO2->FIODIR = 0xffffffff is used to configure all PORT2 pins as OUTPUT.

The program then enters an infinite loop (while(1)) where it turns ON and OFF two sets of pins (0x50 and 0x60) repeatedly with a delay of 5 seconds (delay_ms(5000)).

The first set of pins is turned ON (LPC_GPIO2->FIOSET = 0x50) and the second set is turned OFF (LPC_GPIO2->FIOCLR = 0x60).

The program then waits for 5 seconds (delay_ms(5000)).

The first set of pins is turned OFF (LPC_GPIO2->FIOCLR = 0x50) and the second set is turned ON (LPC_GPIO2->FIOSET = 0x60).

The program waits for 5 seconds and then the loop starts over from the beginning.

In summary, this program uses the LPC17xx microcontroller to control two sets of pins as outputs in an infinite loop, with each set turning ON and OFF alternately with a delay of 5 seconds between each transition.