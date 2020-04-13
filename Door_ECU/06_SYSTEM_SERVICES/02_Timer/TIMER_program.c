#include "STD_TYPES.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_register.h"
#include "TIMER_interface.h"



static void (*TIMER0_pvCallBack)(void)=NULL;

void Timer0_voidInit(void)
{
	CLR_BIT(TCCR0,TIMER0_WGM00);
	CLR_BIT(TCCR0,TIMER0_WGM01);
	CLR_BIT(TCCR0,TIMER0_CS02) ;
	SET_BIT(TCCR0,TIMER0_CS01) ;
	CLR_BIT(TCCR0,TIMER0_CS00) ;
	SET_BIT(TIMSK,TIMER0_TOIE0);
	TCNT0=119;
}



void Timer0_voidSetCallBack(void(*Copy_pvCallBackPtr)(void))
{
	if(Copy_pvCallBackPtr!=NULL)
	TIMER0_pvCallBack=Copy_pvCallBackPtr;
}


void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{
	static u8 overflow_count=0;
	overflow_count++
	if(overflow_count == 19 && TIMER0_pvCallBack!=NULL)
	{
		overflow_count=0;
		TIMER0_pvCallBack();
	}
}


