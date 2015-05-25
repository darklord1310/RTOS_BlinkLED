#include "LEDPart3.h"




void LEDPart3()
{
	initLED();
	State state_LED5 = initial;  //initialize state for LED5

	while(1)
	{
		SD_LED5(&state_LED5 , LED5blinkRate);   // state machine function for LED5
	}

}
