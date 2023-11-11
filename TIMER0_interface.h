#ifndef _TIMER0_INTERFACE_H_
#define _TIMER0_INTERFACE_H_


void TIMER0_voidInit();

void TIMER0_voidStart();

void TIMER0_voidStop();

void TIMER0_voidSetTCNT(u8 Copy_u8Data);

u8 TIMER0_voidGetTCNT();

void TIMER0_voidSetOCR(u8 Copy_u8Data);

void TIMER0_voidEnableOverflowInterrupt();

void TIMER0_voidDisableOverflowInterrupt();

void TIMER0_voidDisaableCTCInterrupt();


void TIMER0_voidEnableCTCInterrupt();


void TIMER0_OV_CallBack(void(*Ptr)(void));

void TIMER_CTC_CallBack(void(*Ptr)(void));


void __vector_11(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_11(void);

void __vector_10(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_10(void);




#endif
