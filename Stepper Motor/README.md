# Stepper Motor

A stepper motor is a type of electric motor that rotates in small, precise steps rather than continuously like a conventional motor. It is widely used in a variety of applications, including CNC machines, 3D printers, robotics, and automation systems.

The operation of a stepper motor is based on the interaction of electromagnets and a rotor with teeth. The rotor has a number of teeth that are magnetically attracted to the electromagnets. When the electromagnets are energized in a specific sequence, the rotor rotates by a fixed angle or step.

The number of steps per revolution depends on the number of teeth on the rotor and the number of energization sequences used. Stepper motors can have different numbers of steps per revolution, ranging from a few steps to thousands of steps per revolution.

Stepper motors can be controlled using a variety of techniques, including full-step, half-step, and microstepping. Full-step mode energizes each coil fully, resulting in a larger step size. In half-step mode, the motor is energized in two phases, resulting in smaller step sizes. In microstepping mode, the current is varied gradually, resulting in even smaller step sizes and smoother motion.

Overall, stepper motors offer precise and repeatable positioning, making them ideal for applications that require accurate control over movement, speed, and torque.


## Stepper Motor Forward Program

This is a code for controlling a DC motor connected to pin J8 of the LPC1768 microcontroller board. The connections of the DC motor to the board are not specified in the code, but based on the comments, it is connected to the ST-DC-CNTRL pin of J8.

The code starts with the declaration of a delay function that creates a delay in milliseconds using nested for loops. The main program then defines a function named "Forword()" which is responsible for controlling the direction of the DC motor to move forward. This function sets and clears the pins of PORT2 in a specific order to achieve the desired motion.

The function first clears the second and third bits of PORT2 and sets the fourth bit to move the DC motor forward. It then waits for 100 milliseconds using the delay function. It then clears the fourth bit and sets the sixth bit of PORT2 to continue moving the DC motor forward. It again waits for 100 milliseconds and then clears the sixth bit and sets the fifth bit of PORT2 to continue moving the motor forward. It waits for another 100 milliseconds before finally clearing the fifth bit and setting the fourth bit of PORT2 to continue moving the motor forward. It then waits for another 100 milliseconds before the loop repeats.

The main program initializes the clock and pins of the microcontroller, configures the pins of PORT2 as GPIO, and sets them as output pins. Finally, the program calls the Forword() function to control the DC motor and loop continuously.

## Stepper Motor Reverse Program

This is an embedded C program for controlling a motor in a certain direction. The motor control pins are connected to the microcontroller's GPIO pins. The code initializes the microcontroller and configures the GPIO pins as output.

The function delay_ms is a simple delay function which uses a nested loop to create a delay of ms milliseconds.

The Reverse function controls the motor in the reverse direction by setting and clearing the appropriate GPIO pins in a specific order. In this case, the pins P2.1, P2.2, and P2.3 are used to control the motor. The function sets P2.1 and clears P2.2 and P2.3 to start the motor in reverse direction. Then, it waits for 100 milliseconds using the delay_ms function. Next, it clears P2.1 and sets P2.5 to stop the motor. It waits for 100 milliseconds again. Then, it clears P2.5 and sets P2.6 to keep the motor running in the reverse direction. It waits for 100 milliseconds. Finally, it clears P2.6 and sets P2.1 to stop the motor. It waits for 100 milliseconds and returns from the function.

The main function initializes the microcontroller and configures the GPIO pins. It then enters an infinite loop, calling the Reverse function to keep the motor running in reverse direction.