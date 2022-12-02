#ifndef LED_H_
#define LED_H_
/********************************************************************************
* led.h: Innehåller funktionsdefinitioner för implementering av LEDs.
********************************************************************************/

/* Inkluderingsdirektiv */
#include "misc.h"

/********************************************************************************
* led_t: Strukt för implementering av LEDs och dess in-portar.
*
*       -pin    : LEDens pinnummer på aktuell I/O-port.
*		-io_port: I/O-poten som LEDen är ansluten till.
*		-enabled: Indikerar om lysdioden är tänd.
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
*		   -Pin : Lysdiodens pin-nummer på Arduino Uno
********************************************************************************/
void led_init(led_t* self, 
              const uint8_t pin);

/********************************************************************************
* led_on: Tänder lysdioden
*
*        -self: Pekare till lysdionden som skall tändas.
********************************************************************************/
void led_on(led_t* self);

/********************************************************************************
* led_off: Släcker lysdioden
*
*         -self: Pekare till lysdionden som skall släckas.
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