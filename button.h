#ifndef BUTTON_H_
#define BUTTON_H_
/********************************************************************************
* button.h: Inneh�ller funktionalitet f�r implementering av tryckknappar.
********************************************************************************/

/* Inkluderingsdirektiv */
#include "misc.h"

/********************************************************************************
* button_t: Strukt f�r f�r implementering av tryckknappar.

           -pin              : Tryckknappens pinnummer p� aktuell I/O-port.
           -io_port          : I/O-poten som tryckknappen �r ansluten till.
           -interrupt_enabled: Indikerar om PCI-avbrott �r aktiverat.
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
*		      -Pin : Tryckknappens pin-nummer p� Arduino Uno
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
* button_enable_interrupt: Initierar PCI-avbrott p� tryckknappen.
*
*                         -self: Pekare till tryckknappen d�r PCI-avbrott
*                                ska initieras.
********************************************************************************/
void button_enable_interrupt(button_t* self);

/********************************************************************************
* button_enable_interrupt: Tar bort PCI-avbrott p� tryckknappen.
*
*                         -self: Pekare till tryckknappen d�r PCI-avbrott
*                                ska tas bort.
********************************************************************************/
void button_disable_interrupt(button_t* self);

/********************************************************************************
* button_is_pressed: Indikerar om tryckknappen �r nedtryckt.
*
*                   -self: Pekare till tryckknappen som skall l�sas av.
********************************************************************************/
bool button_is_pressed(button_t* self);

/********************************************************************************
* button_toggle_interrupt: Togglar PCI-avbrott p� angiven tryckknapp.
*
*                         -self: Pekare till tryckknappen d�r PCI-avbrott
*                                skall togglas.
********************************************************************************/
void button_toggle_interrupt(button_t* self);


#endif /* BUTTON_H_ */