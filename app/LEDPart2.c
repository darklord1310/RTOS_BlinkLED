#include "LEDPart2.h"



/*
 *	Describe blinking of LEDs independently
 *
 *	LED3 blinks at 240ms
 *	LED4 blinks at 1 s
 *
 *	The above case is by default, but when user button is pressed
 *	Then,
 *			LED3 blink rate remains same
 *			LED4 blinks at 100ms which is faster than LED3
 *
 */
void LEDPart2()
{
	initLED();
	State state_LED3 = initial;  //initialize state for LED3
	State state_LED4 = initial;  //initialize state for LED4

	int blinkRate = LED4blinkRate;

	while(1)
	{
		SD_LED3(&state_LED3 , LED3blinkRate);						// state machine function for LED3
		SD_LED4_blinkFasterWhenPress(&state_LED4 , &blinkRate);   	// state machine function for LED4
	}

}
