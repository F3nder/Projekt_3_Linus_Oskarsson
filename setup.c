/********************************************************************************
* setup.h: Innehåller funktionsdefinitioner och globala variabler. För
*          styrning av LEDs, tryckknappar och potentiomter.
********************************************************************************/
#include "setup.h"

/* Skapar LED-obejekt, knapp-obejekt och potetiometer-obejekt. */
led_t l1, l2, l3, l4, l5;
button_t b1, b2, b3, b4, b5;
adc_t a1;

/* Skapar globala variabler för om pwm-funktionalltitet ska vara på. */
volatile bool led_1_pwm_on = false;
volatile bool led_2_pwm_on = false;
volatile bool led_3_pwm_on = false;
volatile bool led_4_pwm_on = false;
volatile bool led_5_pwm_on = false;

/* Funktionsdefinitioner */
static void setup_led_init(void);
static void setup_button_init(void);

/************************************************************************
* setup: Initierar LEDs, Tryckknappar och potetiometrar.
************************************************************************/
void setup(void)
{
	setup_led_init();
	setup_button_init();
	adc_init(&a1, A0);
	return;
}

/************************************************************************
* setup_led_init: Initierar LEDs.
************************************************************************/
static void setup_led_init(void)
{
	led_init(&l1, 6);
	led_init(&l2, 7);
	led_init(&l3, 8);
	led_init(&l4, 9);
	led_init(&l5, 10);
	return;
}

/************************************************************************
* setup_button_init: Initierar tryckknappar och aktiverar PCI-avbrott.
************************************************************************/
static void setup_button_init(void)
{
	button_init(&b1, 2);
	button_init(&b2, 3);
	button_init(&b3, 11);
	button_init(&b4, 12);
	button_init(&b5, 13);
	
	button_enable_interrupt(&b1);
	button_enable_interrupt(&b2);
	button_enable_interrupt(&b3);
	button_enable_interrupt(&b4);
	button_enable_interrupt(&b5);
	return;
}