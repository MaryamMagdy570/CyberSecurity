#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_



#define  SET_BIT(res,index) res=res|(1<<index)
#define  TOGGLE_BIT(res,index) res=res^(1<<index)
#define  CLR_BIT(res,index) res=res&(~(1<<index))
#define  GET_BIT(res,index) ((res>>index)&1)



#define CONC_HELPER(X7,X6,X5,X4,X3,X2,X1,X0) 0b##X7##X6##X5##X4##X3##X2##X1##X0
#define CONC(X7,X6,X5,X4,X3,X2,X1,X0) CONC_HELPER(X7,X6,X5,X4,X3,X2,X1,X0)



#define POWER(x,y) ({              							\
						double result = 1.0;             	\
						int i;                            	\
						for (i = 0; i < (y); i++) {       	\
							result *= (x);               	\
						}                                 	\
						result;                           	\
					})

#define DELAY(X) do{ for (u32 i = 0; i <= X; i++)	asm("NOP");}while(0);


#endif 
