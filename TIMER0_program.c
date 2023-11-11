#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"



void (*Timer0_OV_Ptr)(void) = NULL;

void (*Timer0_CTC_Ptr)(void) = NULL;


void TIMER0_voidInit()
{
	//select mode
#if MODE == NORMAL
	CLR_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
#elif MODE == CTC
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	TIMER0_voidEnableCTCInterrupt();
#elif MODE == PWM_FAST
	CLR_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
#elif MODE == PWM_PHASE_CORRECT
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
#endif

}

void TIMER0_voidStart()
{
//clock select
	TCCR0 &= 0b11111000;
	TCCR0 |= PRESCALER;
}

void TIMER0_voidStop()
{
	//clock select
	TCCR0 &= 0b11111000;
	TCCR0 |= NO_CLOCK;
}

void TIMER0_voidSetTCNT(u8 Copy_u8Data)
{
	TCNT0 = Copy_u8Data;
}

u8 TIMER0_voidGetTCNT()
{
	u8 counts = TCNT0;
	return counts;
}

void TIMER0_voidSetOCR(u8 Copy_u8Data)
{
	OCR0 = Copy_u8Data;
}


void TIMER0_voidEnableOverflowInterrupt()
{
	SET_BIT(TIMSK0,TOIE0);
}

void TIMER0_voidDisableOverflowInterrupt()
{
	CLR_BIT(TIMSK0,TOIE0);
}

void TIMER0_voidEnableCTCInterrupt()
{
	SET_BIT(TIMSK0,OCIE0);
}

void TIMER0_voidDisaableCTCInterrupt()
{
	CLR_BIT(TIMSK0,OCIE0);
}



void TIMER0_OV_CallBack(void(*Ptr)(void))
{
	Timer0_OV_Ptr = Ptr;
}
void TIMER_CTC_CallBack(void(*Ptr)(void))
{
	Timer0_CTC_Ptr = Ptr;
}

void __vector_11(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_11(void)
{
	if(Timer0_OV_Ptr!= NULL)
		Timer0_OV_Ptr();
}

void __vector_10(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_10(void)
{
	if(Timer0_CTC_Ptr!= NULL)
		Timer0_CTC_Ptr();
}

