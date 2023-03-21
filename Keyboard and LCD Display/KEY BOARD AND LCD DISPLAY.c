/* Connections */
/* J1 -> LCD-CNTRL  */
/* J6 -> LCD-DATA  */
/* J5 -> KEYPAD-COLOUM  */
/* J8 -> KEYPAD-ROW  */

#include <LPC17xx.h>
#include "keypad.h"
#include "lcd.h"

int main() 
{
    uint8_t key;
    SystemInit();

    /*        RS   RW   EN   D0   D1   D2   D3   D4    D5    D6    D7      P_NC(Not connected)*/
 LCD_SetUp(P0_1,P0_2,P0_3,P1_16,P1_17,P1_18,P1_19,P1_20,P1_21,P1_22,P1_23);
    LCD_Init(2,16);

  KEYPAD_Init(P2_0,P2_1,P2_2,P2_3,P1_0,P1_1,P1_4,P1_8);  // Keypad is connected to P2_0 - P2_3 and P1_0 - P1_3

    LCD_Printf("Key Pressed:");
    while (1) 
    {
        key = KEYPAD_GetKey();     // Read the Ascii value of Key
        LCD_GoToLine(1);
        LCD_DisplayChar(key);      // Display the Key pressed on LCD        
    }    
}
