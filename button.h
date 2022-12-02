#ifndef BUTTON_H_
#define BUTTON_H_
/********************************************************************************
* button.h: Innehåller funktionalitet för implementering av tryckknappar.
********************************************************************************/

/* Inkluderingsdirektiv */
#include "misc.h"

/********************************************************************************
* button_t: Strukt för för implementering av tryckknappar.

           -pin              : Tryckknappens pinnummer på aktuell I/O-port.
           -io_port          : I/O-poten som tryckknappen är ansluten till.
           -interrupt_enabled: Indikerar om PCI-avbrott är aktiverat.
********************************************************************************/
typedef struct
{
	uint8_t pin;
	enum io_port io_port;
	bool interrupt_enabled;
} button_t;


/* Funktionsdefinitioner */
/********************************************************************************
* button_init: Initierar tryckknappar.
*
*             -self: Pekare till tryckknappen som ska initieras.
*		      -Pin : Tryckknappens pin-nummer på Arduino Uno
********************************************************************************/
void button_init(button_t* self, 
                 const uint8_t pin);
				 
/********************************************************************************
* button_clear: Tar bort tryckknappen.
*
*              -self: Pekare till tryckknappen som ska tas bort.
********************************************************************************/
void button_clear(button_t* self);

/********************************************************************************
* button_enable_interrupt: Initierar PCI-avbrott på tryckknappen.
*
*                         -self: Pekare till tryckknappen där PCI-avbrott
*                                ska initieras.
********************************************************************************/
void button_enable_interrupt(button_t* self);

/********************************************************************************
* button_enable_interrupt: Tar bort PCI-avbrott på tryckknappen.
*
*                         -self: Pekare till tryckknappen där PCI-avbrott
*                                ska tas bort.
********************************************************************************/
void button_disable_interrupt(button_t* self);

/********************************************************************************
* button_is_pressed: Indikerar om tryckknappen är nedtryckt.
*
*                   -self: Pekare till tryckknappen som skall läsas av.
********************************************************************************/
bool button_is_pressed(button_t* self);

/********************************************************************************
* button_toggle_interrupt: Togglar PCI-avbrott på angiven tryckknapp.
*
*                         -self: Pekare till tryckknappen där PCI-avbrott
*                                skall togglas.
********************************************************************************/
void button_toggle_interrupt(button_t* self);


#endif /* BUTTON_H_ */