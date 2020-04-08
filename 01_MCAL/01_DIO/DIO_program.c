#include "STD_TYPES.h"

#include "BIT_MATH.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"

#define INPUT_PIN       1
#define OUTPUT_PIN      0

Error_Status setPinDir(u8 Port, u8 Pin, u8 Dir)
{
    Error_Status loc_err = E_NOK;
	switch (Port)
	{
		case 'A':
		           if(Dir == 0)
				   {
					  DDRA = DDRA & ~(1 << Pin); 
				   }
				   else
				   {
					   DDRA = DDRA | (1 << Pin);
				   }
		           loc_err = E_OK;
				   break;
		case 'B':
		          if(Dir == 0)
				   {
					  DDRB = DDRB & ~(1 << Pin); 
				   }
				   else
				   {
					   DDRB = DDRB| (1 << Pin);
				   }
		           loc_err = E_OK;
				   break;
		case 'C':
		          if(Dir == 0)
				   {
					  DDRC = DDRC & ~(1 << Pin); 
				   }
				   else
				   {
					   DDRC = DDRB | (1 << Pin);
				   }
		           loc_err = E_OK;
				   break;
		case 'D':
		          if(Dir == 0)
				   {
					  DDRD = DDRD & ~(1 << Pin); 
				   }
				   else
				   {
					   DDRD = DDRB | (1 << Pin);
				   }
		           loc_err = E_OK;
				   break;
	}
	return loc_err;
}

Error_Status setPinValue(u8 Port, u8 Pin, u8 val)
{
    Error_Status loc_err = E_NOK;
	switch (Port)
	{
		case 'A':
		           if(val == 0)
				   {
					  PORTA = PORTA & ~(1 << Pin); 
				   }
				   else
				   {
					   PORTA = PORTA | (1 << Pin);
				   }
		           loc_err = E_OK;
				   break;
		case 'B':
		          if(val == 0)
				   {
					  PORTB = PORTB & ~(1 << Pin); 
				   }
				   else
				   {
					   PORTB = PORTB| (1 << Pin);
				   }
		           loc_err = E_OK;
				   break;
		case 'C':
		          if(val == 0)
				   {
					  PORTC = PORTC & ~(1 << Pin); 
				   }
				   else
				   {
					   PORTC = PORTC | (1 << Pin);
				   }
		           loc_err = E_OK;
				   break;
		case 'D':
		          if(val == 0)
				   {
					  PORTD = PORTD & ~(1 << Pin); 
				   }
				   else
				   {
					   PORTD = PORTD | (1 << Pin);
				   }
		           loc_err = E_OK;
				   break;
	}
	return loc_err;
}

Error_Status getPinValue(u8 Port, u8 Pin,u8* Result)
{
    Error_Status loc_err = E_NOK;
	switch (Port)
	{
		case 'A':  *Result = GET_BIT(PINA,Pin); loc_err = E_OK; break;
		case 'B':  *Result = GET_BIT(PINB,Pin); loc_err = E_OK; break;
		case 'C':  *Result = GET_BIT(PINC,Pin); loc_err = E_OK; break;
		case 'D':  *Result = GET_BIT(PIND,Pin); loc_err = E_OK; break;
	}
	return loc_err;
}

