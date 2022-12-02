/* Inkluderingsdirektiv */
#include "setup.h"

/* PCI-avbrott för tryckknappar ansluta till pin 11 - 13. */
ISR (PCINT0_vect)
{
	if (button_is_pressed(&b3))
	{
		led_3_pwm_on = !led_3_pwm_on;
	}
	
	else if (button_is_pressed(&b4))
	{
		led_4_pwm_on = !led_4_pwm_on;
	}
	
	else if (button_is_pressed(&b5))
	{
		led_5_pwm_on = !led_5_pwm_on;
	}
}

/* PCI-avbrott för tryckknappar ansluta till pin 2 och 3. */
ISR (PCINT2_vect)
{
		if (button_is_pressed(&b1))
		{
			led_1_pwm_on = !led_1_pwm_on;
		}
		
		else if (button_is_pressed(&b2))
		{
			led_2_pwm_on = !led_2_pwm_on;
		}
		
}