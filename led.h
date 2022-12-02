#ifndef LED_H_
#define LED_H_
/********************************************************************************
* led.h: Inneh�ller funktionsdefinitioner f�r implementering av LEDs.
********************************************************************************/

/* Inkluderingsdirektiv */
#include "misc.h"

/********************************************************************************
* led_t: Strukt f�r implementering av LEDs och dess in-portar.
*
*       -pin    : LEDens pinnummer p� aktuell I/O-port.
*		-io_port: I/O-poten som LEDen �r ansluten till.
*		-enabled: Indikerar om lysdioden �r t�nd.
********************************************************************************/
typedef struct
{
	uint8_t pin;
	enum io_port io_port;
	bool enabled;
} led_t;



/* Funktionsdefinitioner */

/********************************************************************************
* led_init: Initierar lysdioder.
*
*          -self: Pekare till lysdioden som ska initieras.
*		   -Pin : Lysdiodens pin-nummer p� Arduino Uno
********************************************************************************/
void led_init(led_t* self, 
              const uint8_t pin);

/********************************************************************************
* led_on: T�nder lysdioden
*
*        -self: Pekare till lysdionden som skall t�ndas.
********************************************************************************/
void led_on(led_t* self);

/********************************************************************************
* led_off: Sl�cker lysdioden
*
*         -self: Pekare till lysdionden som skall sl�ckas.
********************************************************************************/
void led_off(led_t* self);

/********************************************************************************
* led_toggle: Togglar angiven lysdiod.
*
*            -self: Pekare till lysdionden som skall togglas.
********************************************************************************/
void led_toggle(led_t* self);

/********************************************************************************
* led_blink: Blinkar angiven lysdiod.
*
*           -self:          Pekare till lysdionden som skall togglas.
*           -delay_time_ms: Blikhastighet i millisekunder.
********************************************************************************/
void led_blink(led_t* self,
               uint16_t delay_time_ms);

#endif /* LED_H_ */