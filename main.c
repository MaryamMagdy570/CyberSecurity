/*
 * main.c
 *
 *  Created on: Nov 10, 2023
 *      Author: Maryam Magdy
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "CLCD_interface.h"
#include "TIMER0_interface.h"



u8 service[2];
u8 sub_service[2];
u8 routine[4];
u8 routine_saved[4]={'A','A','0','0'};

u8 check_flag =1;
u8 Routine_check =1;

volatile u8 random_decimal[4];
char random_hexa[4][3];
u8 encrypted_by_ECU[4];
char encrypted_by_USER[4][3];

typedef enum
{
	no_access,
	wait_for_access,
	accessed,

}state_type;


 state_type state = no_access;


 u8 asciiHexToDecimal(const char *hexString);

 void decimalToAsciiHexString(u8 decimalValue, char *hexString);


int main(void)
{
	DIO_voidInit();
	USART_voidInit();
	CLCD_voidInit();
	TIMER0_voidInit();
	TIMER0_voidStart();


	while(1)
	{

		service[0] = USART_u8Receive();
		service[1] = USART_u8Receive();

		sub_service[0] = USART_u8Receive();
		sub_service[1] = USART_u8Receive();

		if (service[0] == '2' && service[1] == '7' && sub_service[0] == '0'&& sub_service[1] == '1' && state == no_access)
		{
			CLCD_voidSendCommand(CLCD_CMD_CLEAR_DISPLAY);
			CLCD_voidGoToRowColumn(0,0);
			CLCD_voidSendString("67 01");


			for (int i =0;i<4;i++)
			{
				random_decimal[i] = TIMER0_voidGetTCNT();  //from timer
				encrypted_by_ECU[i] =  random_decimal[i] + 1;
				decimalToAsciiHexString(random_decimal[i],random_hexa[i]);
				CLCD_voidSendData(' ');
				CLCD_voidSendString(random_hexa[i]);
			}

			state = wait_for_access;
		}

		else if (service[0] == '2' && service[1] == '7' && sub_service[0] == '0'&& sub_service[1] == '2' && state == wait_for_access)
		{
			for (int i=0; i<4; i++)
			{
				for (int j=0; j<2;j++ )
				{
					encrypted_by_USER[i][j] = USART_u8Receive();
				}
				encrypted_by_USER[i][2] = '\0';
			}


			for (int i =0;i<4;i++)
			{
				if (encrypted_by_ECU[i] != asciiHexToDecimal(encrypted_by_USER[i]))
					check_flag = 0;
			}

			CLCD_voidSendCommand(CLCD_CMD_CLEAR_DISPLAY);
			CLCD_voidGoToRowColumn(0,0);

			if(check_flag)
			{
				state = accessed;
				CLCD_voidSendCommand(CLCD_CMD_CLEAR_DISPLAY);
				CLCD_voidGoToRowColumn(0,0);
				CLCD_voidSendString("67 02");
			}
			else
			{
				state = no_access;
				check_flag = 1;
				CLCD_voidSendCommand(CLCD_CMD_CLEAR_DISPLAY);
				CLCD_voidGoToRowColumn(0,0);
				CLCD_voidSendString("7F 27 35");
			}
		}
		else if (service[0] == '3' && service[1] == '1' && sub_service[0] == '0' && sub_service[1] == '1')
		{
			for (int i=0 ; i<4; i++)
				routine[i] = USART_u8Receive();


			for (int i=0 ; i<4; i++)
				if(	routine[i] != routine_saved[i])
					Routine_check =0;


			if (state == accessed && Routine_check)
			{
				CLCD_voidSendCommand(CLCD_CMD_CLEAR_DISPLAY);
				CLCD_voidGoToRowColumn(0,0);
				CLCD_voidSendString("71 01 AA 00");
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_HIGH);  //LED
			}
			else
			{
				Routine_check = 1;
				CLCD_voidSendCommand(CLCD_CMD_CLEAR_DISPLAY);
				CLCD_voidGoToRowColumn(0,0);
				CLCD_voidSendString("NRC 7F 31 35");
			}
		}

		while(13 != USART_u8Receive())
		{
			//polling
		}
	}
return 0;
}







u8 asciiHexToDecimal(const char *hexString) {
    u8 decimalValue = 0;

    if (hexString == NULL) {
        return 0;
    }

    while (*hexString) {
        char c = *hexString++;

        if (c >= '0' && c <= '9') {
            decimalValue = (decimalValue << 4) | (c - '0');
        } else if (c >= 'A' && c <= 'F') {
            decimalValue = (decimalValue << 4) | (c - 'A' + 10);
        } else if (c >= 'a' && c <= 'f') {
            decimalValue = (decimalValue << 4) | (c - 'a' + 10);
        } else {
            // Handle invalid character, if needed
            // For simplicity, this example ignores non-hex characters
            return 0;
        }
    }

    return decimalValue;
}

void decimalToAsciiHexString(u8 decimalValue, char *hexString) {
    const char hexDigits[] = "0123456789ABCDEF";

    hexString[0] = hexDigits[(decimalValue >> 4) & 0xF];
    hexString[1] = hexDigits[decimalValue & 0xF];
    hexString[2] = '\0';  // Null-terminate the string
}


