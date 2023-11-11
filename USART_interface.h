#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_


//#define DOUBLE_SPEED_MODE 	0
//#define DOUBLE_SPEED_MODE 	3

void USART_voidInit();
void USART_voidTransmit(u8 Copy_u8Data);
u8 USART_u8Receive();


#endif
