#ifndef _USART_PRIVATE_H_
#define _USART_PRIVATE_H_


#define BAUD_RATE_ASYNC_NORMAL(baud_rate) ((F_CPU / (16UL * (baud_rate))) - 1)
#define BAUD_RATE_ASYNC_DOUBLE(baud_rate) ((F_CPU / (8UL * (baud_rate))) - 1)
#define BAUD_RATE_SYNC_MASTER(baud_rate)  ((F_CPU / (2UL * (baud_rate))) - 1)

/***** PIN CONFIGURATION *****/

/*  UCSRA */
#define RXC 	7
#define TXC 	6
#define UDRE 	5
#define FE  	4
#define DOR  	3
#define PE  	2
#define U2X  	1
#define MPCM  	0

/*  UCSRB */
#define RXCIE 	7
#define TXCIE 	6
#define UDRIE 	5
#define RXEN  	4
#define TXEN  	3
#define UCSZ2  	2
#define RXB8  	1
#define TXB8  	0


/*  UCSRC */
#define URSEL 	7
#define UMSEL 	6
#define UPM1 	5
#define UPM0  	4
#define USBS  	3
#define UCSZ1  	2
#define UCSZ0  	1
#define UCPOL  	0


/*  UBBRH */
#define URSEL 	7




#endif
