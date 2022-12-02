/********************************************************************************
* main.c: PWM-styrning av 5 LEDs, varje LED aktiveras via en enskilld tryckknapp.
********************************************************************************/

/* Inkluderingsdriektiv */
#include "setup.h"

/********************************************************************************
* main: Anropar funktionen setup och pwm-run.
********************************************************************************/
int main(void)
{
	setup();
	pwm_run();
    while (1)
    {
    }
	return 0;
}
