#include "ConfigureLED.h"
#include "LEDsStateMachine.h"
#include "LEDPart1.h"
#include "LEDPart2.h"
#include "LEDPart3.h"

typedef struct
{
	State state;
}TaskBlock;


#define yield(x) (x)->state = __LINE__; break; case __LINE__ : ;
#define startTask(x) switch( (x)->state) { case 0: ;
#define initTaskBlock(x) (x)->state = 0;
#define endTask(x) } ;




void testingSwitchCase(TaskBlock *tb)
{
	static int here = 0;

	startTask(tb);

	here = 0;
	yield(tb);
	here = 1;
	yield(tb);
	here = 2;
	yield(tb);
	here = 3;
	yield(tb);

	endTask(tb);
}

void ThreeLEDCasesInOne()
{
		initLED();
		State state_LED3 = initial;  //initialize state for LED3
		State state_LED4 = initial;  //initialize state for LED4
		State state_LED5 = initial;  //initialize state for LED5

		int blinkRate = LED4blinkRate;

		while(1)
		{
			SD_LED3(&state_LED3 , LED3blinkRate);
			SD_LED4_blinkFasterWhenPress(&state_LED4 , &blinkRate);
			SD_LED5(&state_LED5 , LED5blinkRate);
		}
}



int main(void)
{
	ThreeLEDCasesInOne();
	return 0;
}
