#ifndef _TIMER0_CONFIG_H_
#define _TIMER0_CONFIG_H_

/* choose: NORMAL,CTC,PWM_FAST,PWM_PHASE_CORRECT */
#define MODE	 NORMAL

/* choose: DISCONNECTED,SET,CLEAR,TOGGLE */
#define OC_PIN_BEHAVIOR   00

/* choose : NO_CLOCK,NO_PRESCALER,DIVIDE_BY_8,DIVIDE_BY_64,DIVIDE_BY_256,DIVIDE_BY_1024
 * 			ON_FALLING_EDGE,ON_RISING_EDGE */
#define PRESCALER		NO_PRESCALER




#endif
