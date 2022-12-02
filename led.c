/********************************************************************************
* led.h: Innehåller funktionsdefinitioner för implementering av LEDs.
********************************************************************************/
#include "led.h"

/********************************************************************************
* led_init: Initierar lysdioder.
*
*          -self: Pekare till lysdioden som ska initieras.
*		   -Pin : Lysdiodens pin-nummer på Arduino Uno
********************************************************************************/
void led_init(led_t* self,
              const uint8_t pin)
{
	if (pin >= 0 && pin <= 7)
	{
		self->io_port = IO_PORTD;
		self->pin = pin;
		DDRD |= (1 << self->pin);
	}
	else if (pin >= 8 && pin <= 13)
	{
		self->io_port = IO_PORTB;
		self->pin = pin - 8;
		DDRB |= (1 << self->pin);
	}
	
	self->enabled = false;
	return;
}

/********************************************************************************
* led_on: Tänder lysdioden
*
*        -self: Pekare till lysdionden som skall tändas.
********************************************************************************/
void led_on(led_t* self)
{
	if (self->io_port == IO_PORTD)
	{
		PORTD |= (1 << self->pin);
	}
	else if (self->io_port == IO_PORTB)
	{
		PORTB |= (1 << self->pin);
	}
	
	self->enabled = true;
	return;
}

/********************************************************************************
* led_off: Släcker lysdioden
*
*         -self: Pekare till lysdionden som skall släckas.
********************************************************************************/
void led_off(led_t* self)
{
		if (self->io_port == IO_PORTD)
		{
			PORTD &= ~(1 << self->pin);
		}
		else if (self->io_port == IO_PORTB)
		{
			PORTB &= ~(1 << self->pin);
		}
		
		self->enabled = false;
		return;
}

/********************************************************************************
* led_toggle: Togglar angiven lysdiod.
*
*            -self: Pekare till lysdionden som skall togglas.
********************************************************************************/
void led_toggle(led_t* self)
{
	if (self->enabled == false)
	{
		led_on(self);
	}
	else 
	{
		led_off(self);
	}
	return;
}

/********************************************************************************
* led_blink: Blinkar angiven lysdiod.
*
*           -self:          Pekare till lysdionden som skall togglas.
*           -delay_time_ms: Blikhastighet i millisekunder.
********************************************************************************/
void led_blink(led_t* self,
               uint16_t delay_time_ms)
{
    led_on(self);
	delay_ms(delay_time_ms);
	led_off(self);
	delay_ms(delay_time_ms);
	return;
}