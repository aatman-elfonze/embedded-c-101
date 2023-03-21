/* Connections */
/* J3 8TH PIN -> CRO POSITIVE PROBE  */
/* GND PIN -> CRO NEGATIVE PROBE  */

#include <lpc17xx.h>

void initTimer0(void);
void delayMS(unsigned int milliseconds);

int main(void)
{
	SystemInit(); //gets called by Startup code before main(), sets CCLK = 100Mhz
	initTimer0();
	LPC_PINCON->PINSEL1 |= (1<<21); //Select AOUT function for P0.26 , bits[21:20] = [10] 
	unsigned int value=0; //Binary value used for Digital To Analog Conversion
	while(1)
	{
		
		//For 10-bit DAC max-value is 2^10 - 1 = 1023
		for(value=0;value<1023;value++)
		{
		LPC_DAC->DACR = (value<<6);
		//delayMS(1);
		}
			for(value=1023;value>0;value--)
		{
		LPC_DAC->DACR = (value<<6);
	//	delayMS(1);
		}
		
	}
}

void initTimer0(void)
{

	//Assuming that PLL0 has been setup with CCLK = 60Mhz
	//using default PCLK = 25 which is configure by startup code
	LPC_TIM0->CTCR = 0x0;
	LPC_TIM0->PR = 25000-1; //25000 clock cycles @25Mhz PCLK = 1 ms
	LPC_TIM0->TCR = 0x02; //Reset Timer
}

void delayMS(unsigned int milliseconds) //Using Timer0
{
	LPC_TIM0->TCR = 0x02; //Reset Timer
	LPC_TIM0->TCR = 0x01; //Enable timer
	while(LPC_TIM0->TC < milliseconds); //wait until timer counter reaches the desired delay
	LPC_TIM0->TCR = 0x00; //Disable timer
}
