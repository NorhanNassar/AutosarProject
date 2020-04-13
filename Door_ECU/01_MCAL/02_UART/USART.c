/*
 * USART.c
 *
 *  Created on: Mar 28, 2020
 *      Author: Norhan Nassar
 */


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "USART.h"

#  define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)

txCbf_t appTxNotify;
rxCbf_t appRxNotify;

typedef enum
{
	ideal,
	busy
} bufferState_t;
typedef struct
{
	u8* ptrToDataBuffer;
	u32 Position;
	u32 Size;
	bufferState_t State;
}dataBuffer_t;

#define NULL (void*)0



static dataBuffer_t txBuffer={0};
static dataBuffer_t rxBuffer={0};
extern USART_Init_Cfg_t USART_Init_Cfg;

//static Error_Status USART_SendByTask(u8* bufferData, u32 bytesCount);

Error_Status USART_Init()
{
	u32 tempReg;
		/* Configure GPIO Pins for USART1	*/
	Error_Status Local_Error=E_OK;
	Local_Error|=setPinDir('D',0,0); /*set rx pin to input*/
	Local_Error|=setPinValue('D',0,1);
	Local_Error|=setPinDir('D',1,1); /*set tx pin to output*/
	
	UCSRB=	USART_Init_Cfg.Enable_Interrupts | TE_EN | RE_EN;
	UCSRC=0x80 | USART_Init_Cfg.ParityBit | USART_Init_Cfg.NumberOfStopBits | DATA_BITS_EIGHT; 
	
	UBRRL=BUADRATE_9600_8MHZ;

	return Local_Error;
}



Error_Status USART_Send(u8* bufferData, u32 bytesCount)
{
	u32 i;
	if((txBuffer.State == ideal)&&(bufferData)&&(bytesCount>0))
	{
		txBuffer.ptrToDataBuffer = bufferData;
		txBuffer.Size = bytesCount;
		txBuffer.Position = 0;
		txBuffer.State = busy;

		for(i=0;i<bytesCount;i++)										/* to save all data that will be transmitted */
			txBuffer.ptrToDataBuffer[i] = bufferData[i];


		UDR = txBuffer.ptrToDataBuffer[txBuffer.Position];		/* to make it enter USART handler first time */
		txBuffer.Position++;

		return E_OK;
	}
	return E_NOK;
}




Error_Status USART_Recieve(u8* bufferData, u32 bytesCount)
{
	if((rxBuffer.State == ideal)&&(bufferData)&&(bytesCount>0))
	{
		rxBuffer.ptrToDataBuffer = bufferData;
		rxBuffer.Size = bytesCount;
		rxBuffer.Position = 0;
		rxBuffer.State=busy;

		return E_OK;
	}
	return E_NOK;
}



Error_Status USART_setTxCbf (txCbf_t txCbf)
{
	if(txCbf)
	{
		appTxNotify = txCbf;
		return E_OK;
	}
	return E_NOK;
}

Error_Status USART_setRxCbf (rxCbf_t rxCbf)
{
	if(rxCbf)
	{
		appRxNotify = rxCbf;
		return E_OK;
	}
	return E_NOK;
}


ISR(RX_INT){
	u8 tempToClear=0;
	if(rxBuffer.State == busy)
	{
		rxBuffer.ptrToDataBuffer[rxBuffer.Position]=UDR;    /* first step to clear the flag */
		rxBuffer.Position++;
		if(rxBuffer.Position == rxBuffer.Size)
		{
			rxBuffer.Position =0;
			rxBuffer.Size =0;
			rxBuffer.ptrToDataBuffer =NULL;
			rxBuffer.State = ideal;
			if(appRxNotify)
				appRxNotify();
		}
	}
	else
		tempToClear = UDR;
}
ISR(TX_INT){
	UCSRA |= TXE_FLAG;			/* to clear TXE flag */
	if(txBuffer.Position!=txBuffer.Size)
	{
		/* There is a data to be sent */
		UDR = txBuffer.ptrToDataBuffer[txBuffer.Position];
		txBuffer.Position++;
	}
	else
	{
		/* Transmission end */
		txBuffer.Position =0;
		txBuffer.Size =0;
		txBuffer.ptrToDataBuffer =NULL;
		txBuffer.State = ideal;

		if(appTxNotify)
			appTxNotify();
	}
}
