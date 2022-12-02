/********************************************************************************
* misc.c: Inneh�ller delay funktioner.
********************************************************************************/
#include "misc.h"

/********************************************************************************
* delay_ms: Genererar f�rdr�jning m�tt i millisekunder.
*
*           - delay_time_ms: Angiven f�rdr�jningstid i millisekunder.
********************************************************************************/
void delay_ms(const uint16_t delay_time_ms)
{
   for (uint16_t i = 0; i < delay_time_ms; ++i)
   {
      _delay_ms(1);
   }
   return;
}

/********************************************************************************
* delay_us: Genererar f�rdr�jning m�tt i mikrosekunder.
*
*           - pwm_period_us: Angiven f�rdr�jningstid i mikrosekunder.
********************************************************************************/
void delay_us(const uint16_t pwm_period_us)
{
	for (uint16_t i = 0; i < pwm_period_us; ++i)
	{
		_delay_us(1);
	}

   return;
}
