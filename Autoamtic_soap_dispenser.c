#include <lpc17xx.h>
#define PRESCALE (25-1)
#define TRIG (1<<0) //P0.0
#define ECHO (1<<1) //P0.1
LPC_PINCON->PINSEL0 = 0xFFFF00FF;//P0.4 to P0.7 GPIO
LPC_GPIO0->FIODIR = 0x000000F0;//P0.4 to P0.7 output
void initTimer0(void) //PCLK must be = 25Mhz!
{
	LPC_TIM0->CTCR = 0x0;
	LPC_TIM0->PR = PRESCALE; //Increment TC at every 24999+1 clock cycles
	LPC_TIM0->TCR = 0x02; //Reset Timer
}

void startTimer0(void)
{
	LPC_TIM0->TCR = 0x02; //Reset Timer
	LPC_TIM0->TCR = 0x01; //Enable timer
}

unsigned int stopTimer0(void)
{
	LPC_TIM0->TCR = 0x00; //Disable timer
	return LPC_TIM0->TC;
}

void delayUS(unsigned int microseconds) //Using Timer0
{
	LPC_TIM0->TCR = 0x02; //Reset Timer
	LPC_TIM0->TCR = 0x01; //Enable timer
	while(LPC_TIM0->TC < microseconds); //wait until timer counter reaches the desired delay
	LPC_TIM0->TCR = 0x00; //Disable timer
}

void delayMS(unsigned int milliseconds) //Using Timer0
{
	delayUS(milliseconds * 1000);
}
void clock_wise(void)
{
    var1 = 0x00000008;
    for(i=0;i<=3;i++)
    {
        var1 = var1<<1;
        LPC_GPIO0->FIOPIN = var1;
        for(k=0;k<3000;k++);
    }
}
void anti_clock_wise(void)
{   var1 = 0x00000100;
    for(i=0;i<=3;i++)
        {
        var1 = var1>>1;
        LPC_GPIO0->FIOPIN = var1;
        for(k=0;k<3000;k++);
        }
}
int main(void)
{
	SystemInit();
	initTimer0();
	int echoTime=0;
	float distance=0;

	LPC_GPIO0->FIODIR |= TRIG;    //Set P0.2(TRIG) as output
	LPC_GPIO0->FIODIR &= ~(ECHO); //Set P0.3(ECHO) as input (explicitly)
	LPC_GPIO0->FIOCLR |= TRIG;    //Set P0.2 LOW initially

	while(1)
	{
		//Output 10us HIGH on TRIG pin
		LPC_GPIO0->FIOPIN |= TRIG;
		delayUS(10);
		LPC_GPIO0->FIOCLR |= TRIG;

		while(!(LPC_GPIO0->FIOPIN & ECHO)); //Wait for a HIGH on ECHO pin
		startTimer0(); //Start counting
		while(LPC_GPIO0->FIOPIN & ECHO); //Wait for a LOW on ECHO pin
		echoTime = stopTimer0(); //Stop counting and save value(us) in echoTime

		distance = (0.0343 * echoTime)/2; //Find the distance

		if(distnce < 20)
        {
            for(j=0;j<12;j++)
            clock_wise();
            delayMS(100);
            for(j=0;j<12;j++)
            anti_clock_wise(void)
        }

		delayMS(1000); //1 update per second
	}
	return 0;
}
