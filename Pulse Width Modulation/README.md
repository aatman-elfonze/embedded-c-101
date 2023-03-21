# Pulse Width Modulation

PWM stands for Pulse Width Modulation, which is a technique used in electronics and control systems to control the amount of power delivered to a device such as a motor or LED.

PWM works by rapidly turning the power on and off at a specific frequency, with the amount of time that the power is on (the duty cycle) determining the average power delivered to the device. For example, if the power is on for 50% of the time and off for the other 50%, the average power delivered to the device will be 50% of the maximum power.

By varying the duty cycle of the PWM signal, the power delivered to the device can be varied, allowing for precise control of the device's operation. PWM is commonly used in applications such as motor speed control, LED brightness control, and power conversion.

PWM can be generated using specialized hardware, such as microcontrollers or dedicated PWM controllers, or it can be generated using software on a general-purpose microcontroller or computer. The frequency and duty cycle of the PWM signal can be adjusted depending on the requirements of the application.

## Explanation of the program

This is a C program that configures pins P2_0-P2_3 of LPC1768 microcontroller for PWM mode, generates a PWM signal with a cycle time of 100ms and duty cycle ranging from 0-100%, and then loops indefinitely between increasing and decreasing the duty cycle from 0-100% and 100-0%, respectively.

The program starts by defining a function delay_ms() that introduces a delay of specified milliseconds.

Next, it defines several constants and macros to be used in the program, including SBIT_CNTEN and SBIT_PWMEN for enabling PWM module and counters, SBIT_PWMMR0R for resetting PWM on PWMMR0, SBIT_LEN0-SBIT_LEN4 for latch enable bits, SBIT_PWMENA1-SBIT_PWMENA4 for enabling PWM output pins, and PWM_1-PWM_4 for pins P2_0-P2_3 in PWM mode.

In the main() function, it first initializes the system by calling SystemInit() function. It then sets up pins P2_0-P2_3 for PWM mode using LPC_PINCON->PINSEL4 register.

Next, it enables PWM module and counters using LPC_PWM1->TCR register and sets the prescalar to 0 using LPC_PWM1->PR register. It also sets the PWMMR0R bit using LPC_PWM1->MCR register to reset PWM on PWMMR0 and reset TC if it matches MR0.

It then sets the MR0 register to 100 to generate a PWM cycle of 100ms, and sets the MR1-MR4 registers to 50 to set the duty cycle to 50% for all four channels. It triggers the latch enable bits using LPC_PWM1->LER register to load the new match values, and enables the PWM output pins using LPC_PWM1->PCR register.

Finally, it loops indefinitely between increasing and decreasing the duty cycle using for loops. In the first loop, it increases the duty cycle from 0-100% by setting the MR1-MR4 registers to duty cycle values and triggers the latch enable bits using LPC_PWM1->LER register. It then delays for 5ms using the delay_ms() function. In the second loop, it decreases the duty cycle from 100-0% by setting the MR1-MR4 registers to duty cycle values and triggering the latch enable bits using LPC_PWM1->LER register. It then delays for 5ms using the delay_ms() function. This loop continues indefinitely.

Note that it is recommended to connect J8 1st pin to CRO positive probe and GND pin to CRO negative probe for observing the PWM signal on an oscilloscope.