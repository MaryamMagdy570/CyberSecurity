#ifndef _TIMER0_PRIVATE_H_
#define _TIMER0_PRIVATE_H_

#define NORMAL				0
#define CTC					1
#define PWM_FAST			2
#define PWM_PHASE_CORRECT	3

//OC
#define DISCONNECTED		0
#define SET					1
#define CLEAR				2
#define TOGGLE				3


#define  NO_CLOCK			0b000
#define  NO_PRESCALER		0b001
#define  DIVIDE_BY_8		0b010
#define  DIVIDE_BY_64       0b011
#define  DIVIDE_BY_256		0b100
#define  DIVIDE_BY_1024		0b101
#define  ON_FALLING_EDGE	0b110
#define  ON_RISING_EDGE 	0b111






/******* PIN CONFIGURATION ********/
#define  WGM00		6
#define  COM01		5
#define  COM00		4
#define  WGM01		3
#define  CS02		2
#define  CS01		1
#define  CS00		0



#define  OCIE0		1
#define  TOIE0		0




#endif
