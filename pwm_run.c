/* Inkluderingsdirektiv */
#include "setup.h"

/************************************************************************
* pwm_run: Funktion för att köra pwm-funktionen.
************************************************************************/
void pwm_run(void)
{
	while (1)
	{
		adc_get_pwm_values(&a1, 1000);
		
		if (led_1_pwm_on) led_on(&l1);
		if (led_2_pwm_on) led_on(&l2);
		if (led_3_pwm_on) led_on(&l3);
		if (led_4_pwm_on) led_on(&l4);
		if (led_5_pwm_on) led_on(&l5);
		
		delay_us(a1.pwm_on_us);
		
		led_off(&l1);
		led_off(&l2);
		led_off(&l3);
		led_off(&l4);
		led_off(&l5);
		
		delay_us(a1.pwm_off_us);
	}
		return;
}
