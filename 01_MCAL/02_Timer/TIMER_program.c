#include "STD_TYPES.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"
#include "TIMER_register.h"



static void (*TIMER0_pvCallBack)(void)=NULL;


Error_Status Timer0_voidInit(void)
{
	CLR_BIT(TCCR0,TIMER0_WGM00);
	CLR_BIT(TCCR0,TIMER0_WGM01);
	CLR_BIT(TCCR0,TIMER0_CS02) ;
	SET_BIT(TCCR0,TIMER0_CS01) ;
	SET_BIT(TCCR0,TIMER0_CS00) ;
	SET_BIT(TIMSK,TIMER0_TOIE0);
	TCNT0=131;
	return E_OK;
}



Error_Status Timer0_voidSetCallBack(void(*Copy_pvCallBackPtr)(void))
{
	if(Copy_pvCallBackPtr!=NULL)
	{
	    TIMER0_pvCallBack=Copy_pvCallBackPtr;
	    return E_OK;
	}
	else
	    return E_NOK;

}


void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{
	if(TIMER0_pvCallBack!=NULL)
	{
		TIMER0_pvCallBack();
	}
}


