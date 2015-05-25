#include "LEDPart1.h"


/*
 *	Describe blinking of LEDs independently
 *
 *	LED3 blinks at 240ms
 *	LED4 blinks at 1 s
 *
 */
void LEDPart1()
{
	initLED();
	State state_LED3 = initial;  //initialize state for LED3
	State state_LED4 = initial;  //initialize state for LED4

	while(1)
	{
		SD_LED3(&state_LED3 , LED3blinkRate);		// state machine function for LED3
		SD_LED4(&state_LED4 , LED4blinkRate);   	// state machine function for LED4
	}
}
