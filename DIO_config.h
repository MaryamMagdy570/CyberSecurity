#ifndef _DIO_CONFIG_H_
#define _DIO_CONFIG_H_




#define DIO_CONFIG 1
/* 1 FOR PRECONFIG , 2 FOR POSTTCONFIG */


/* in case you chose pre-configure please configure the following*/
/* INPUT or OUTPUT */

#define A0 DIO_u8PIN_INPUT
#define A1 DIO_u8PIN_INPUT
#define A2 DIO_u8PIN_OUTPUT    //LCD
#define A3 DIO_u8PIN_OUTPUT    //LCD
#define A4 DIO_u8PIN_INPUT
#define A5 DIO_u8PIN_OUTPUT
#define A6 DIO_u8PIN_OUTPUT
#define A7 DIO_u8PIN_OUTPUT

#define B0 DIO_u8PIN_OUTPUT    //LCD
#define B1 DIO_u8PIN_OUTPUT    //LCD
#define B2 DIO_u8PIN_OUTPUT	   //LCD
#define B3 DIO_u8PIN_OUTPUT
#define B4 DIO_u8PIN_OUTPUT    //LCD
#define B5 DIO_u8PIN_OUTPUT
#define B6 DIO_u8PIN_OUTPUT
#define B7 DIO_u8PIN_OUTPUT

#define C0 DIO_u8PIN_OUTPUT
#define C1 DIO_u8PIN_OUTPUT
#define C2 DIO_u8PIN_OUTPUT
#define C3 DIO_u8PIN_OUTPUT
#define C4 DIO_u8PIN_OUTPUT
#define C5 DIO_u8PIN_OUTPUT
#define C6 DIO_u8PIN_OUTPUT
#define C7 DIO_u8PIN_OUTPUT

#define D0 DIO_u8PIN_INPUT		//UART RX
#define D1 DIO_u8PIN_OUTPUT     //UART TX
#define D2 DIO_u8PIN_INPUT
#define D3 DIO_u8PIN_INPUT
#define D4 DIO_u8PIN_OUTPUT
#define D5 DIO_u8PIN_INPUT
#define D6 DIO_u8PIN_INPUT
#define D7 DIO_u8PIN_INPUT

#endif
