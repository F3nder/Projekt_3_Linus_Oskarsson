#ifndef SETUP_H_
#define SETUP_H_
/********************************************************************************
* setup.h: Innehåller funktionsdefinitioner och globala variabler. För 
*          styrning av LEDs, tryckknappar och potentiomter.
********************************************************************************/

/* Inkluderingsdirektiv */
#include "led.h"
#include "adc.h"
#include "button.h"
#include "misc.h"

/* Skapar LED-obejekt, knapp-obejekt och potetiometer-obejekt. */
extern led_t l1, l2, l3, l4, l5;
extern button_t b1, b2, b3, b4, b5;
extern adc_t a1;

/* Skapar globala variabler för om pwm-funktionalltitet ska vara på. */
extern volatile bool led_1_pwm_on;
extern volatile bool led_2_pwm_on;
extern volatile bool led_3_pwm_on;
extern volatile bool led_4_pwm_on;
extern volatile bool led_5_pwm_on;


/* Funktionsdefinitioner */
/************************************************************************
* setup: Initierar LEDs, Tryckknappar och potetiometrar. 
************************************************************************/
void setup(void);

/************************************************************************
* pwm_run: Funktion för att köra pwm-funktionen.
************************************************************************/
void pwm_run(void);


#endif /* SETUP_H_ */