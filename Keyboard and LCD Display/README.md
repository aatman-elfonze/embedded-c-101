# Communicating with LCD display with a Keyboard

This program is designed to demonstrate the use of a keypad to receive input and display it on an LCD screen. The program initializes the keypad and the LCD and continuously reads input from the keypad and displays it on the LCD screen.

The connections of the keypad and LCD to the LPC1769 microcontroller are specified in the comments. The program uses two header files, "keypad.h" and "lcd.h", to abstract the details of interacting with the hardware.

The program starts by initializing the system and setting up the LCD screen with the specified pins for the control and data lines. It then initializes the keypad with the specified pin connections.

The program enters a loop that continuously reads input from the keypad using the KEYPAD_GetKey() function. The ASCII value of the key pressed is returned and stored in the variable "key". The program then moves the LCD cursor to the first line and displays the character using the LCD_DisplayChar() function.

The program continues to run in this loop, updating the LCD screen with each new key press until it is manually stopped.