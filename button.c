#include "button.h"

/********************************************************************************
* button_init: Initierar tryckknappar.
*
*             -self: Pekare till tryckknappen som ska initieras.
*		      -Pin : Tryckknappens pin-nummer på Arduino Uno
********************************************************************************/
void button_init(button_t* self,
                 const uint8_t pin)
{
	if (pin >= 0 && pin <= 7)
	{
		self->io_port = IO_PORTD;
		self->pin = pin;
		PORTD |= (1 << self->pin);
	}
	else if (pin >= 8 && pin <= 13)
	{
		self->io_port = IO_PORTB;
		self->pin = pin - 8;
		PORTB |= (1 << self->pin);
	}
	
	self->interrupt_enabled = false;
	return;
}

/********************************************************************************
* button_clear: Tar bort tryckknappen.
*
*              -self: Pekare till tryckknappen som ska tas bort.
********************************************************************************/
void button_clear(button_t* self)
{
	button_disable_interrupt(self);
	
	if (self->io_port == IO_PORTB)
	{
		PORTB &= ~(1 << self->pin);
	}
	else if (self->io_port == IO_PORTD)
	{
		PORTD &= ~(1 << self->pin);
	}
	return;
}

/********************************************************************************
* button_enable_interrupt: Initierar PCI-avbrott på tryckknappen.
*
*                         -self: Pekare till tryckknappen där PCI-avbrott
*                                ska initieras.
********************************************************************************/
void button_enable_interrupt(button_t* self)
{
	asm("SEI");
	
	if (self->io_port == IO_PORTB)
	{
		PCICR |= (1 << PCIE0);
		PCMSK0 |= (1 << self->pin);
	}
	else if (self->io_port == IO_PORTD)
	{
		PCICR |= (1 << PCIE2);
		PCMSK2 |=  (1 << self->pin);
	}
	self->interrupt_enabled = true;
	return;
}

/********************************************************************************
* button_enable_interrupt: Tar bort PCI-avbrott på tryckknappen.
*
*                         -self: Pekare till tryckknappen där PCI-avbrott
*                                ska tas bort.
********************************************************************************/
void button_disable_interrupt(button_t* self)
{
	if (self->io_port == IO_PORTB)
	{
		PCMSK0 &= ~(1 << self->pin);
	}
	else if (self->io_port == IO_PORTD)
	{
		PCMSK2 &= ~(1 << self->pin);
	}
	self->interrupt_enabled = false;
	return;
}

/********************************************************************************
* button_is_pressed: Indikerar om tryckknappen är nedtryckt.
*
*                   -self: Pekare till tryckknappen som skall läsas av.
********************************************************************************/
bool button_is_pressed(button_t* self)
{
	if (self->io_port == IO_PORTB)
	{
		return (PINB &(1 << self->pin));
	}
	else if (self->io_port == IO_PORTD)
	{
		return (PIND &(1 << self->pin));
	}
	else return false;
}

/********************************************************************************
* button_toggle_interrupt: Togglar PCI-avbrott på angiven tryckknapp.
*
*                         -self: Pekare till tryckknappen där PCI-avbrott
*                                skall togglas.
********************************************************************************/
void button_toggle_interrupt(button_t* self)
{
	if (self->interrupt_enabled)
	{
		button_disable_interrupt(self);
	}
	else 
	{
		button_enable_interrupt(self);
	}
	return;
}

