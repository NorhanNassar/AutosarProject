/*
 * USART.h
 *
 *  Created on: Mar 28, 2020
 *      Author: Norhan Nassar
 */

#ifndef USART_H_
#define USART_H_

#define UDR 	*((u8*)0x2C)
#define UCSRA 	*((u8*)0x2B)
#define UCSRB 	*((u8*)0x2A)
#define UCSRC 	*((u8*)0x40)
#define UBRRH 	*((u8*)0x40)
#define UBRRL 	*((u8*)0x29)

#define RX_INT __vector_14
#define TX_INT __vector_16

typedef struct
{
	u16 BaudRate; 				/**/
	u16 NumberOfDataBits;		/* Options: DATA_BITS_EIGHT, or DATA_BITS_NINE 				*/
	u16	ParityBit;				/* Options: NO_PARITY, EVEN_PARITY, ODD_PARITY 				*/
	u16 Enable_Interrupts;		/* Options: ENABLE_PARITY_INT, ENABLE_TC_INT, ENABLE_TXE_INT,
											ENABLE_RXNE_INT, ENABLE_IDLE_INT, NO_INT_ENABLED
									Enter here all interrupts you want to enable like:
									ENABLE_PARITY_INT | ENABLE_TC_INT and so on for all
									interrupts you want to be enabled						*/
	u16 NumberOfStopBits;		/* Options:	ONE_STOP_BIT, TWO_STOP_BIT, ONE_HALF_STOP_BIT,
											HALF_STOP_BIT									*/
} USART_Init_Cfg_t;


/* There will be a struct for synchronous type later */

typedef void (*txCbf_t)(void);
typedef void (*rxCbf_t)(void);

#define USART_BASE_ADDRESS				(void*)0x40013800
#define USART1x 						((USARTx volatile * const)USART_BASE_ADDRESS)

/*-------------------------------UCSRA Register---------------------------------*/
#define TXE_FLAG						0x40		/* Transmit data register empty */
#define RXNE_FLAG						0x80		/* Read data register not empty */
/*-------------------------------USART1_CR1 Register--------------------------------*/

#define PCE_PARITY_CONTROL				0x30		/* to enable or disable hardware generation of parity bit
 	 	 	 	 	 	 	 	 	 	 	 	 	 * the computed parity is inserted at the MSB position
 	 	 	 	 	 	 	 	 	 	 	 	 	 * (9th bit if M=1; 8th bit if M=0)				*/


#define TXEIE_TXE_INT_EN				0x40		/* TXE interrupt enable bit
 	 	 	 	 	 	 	 	 	 	 	 	 	 * 0 -> Interrupt is inhibited
 	 	 	 	 	 	 	 	 	 	 	 	 	 * 1 -> A USART interrupt is generated
 	 	 	 	 	 	 	 	 	 	 	 	 	 * whenever TXE=1 in the USART_SR register		*/


#define RXNEIE_RXNE_INT					0x80		/* RXNE interrupt enable bit
 	 	 	 	 	 	 	 	 	 	 	 	 	 * 0 -> Interrupt is inhibited
 	 	 	 	 	 	 	 	 	 	 	 	 	 * 1 -> A USART interrupt is generated
 	 	 	 	 	 	 	 	 	 	 	 	 	 * whenever ORE=1 or RXNE=1
 	 	 	 	 	 	 	 	 	 	 	 	 	 * in the USART_SR register						*/


#define TE_EN							0x08		/* Transmitter enable bit 						*/

#define RE_EN							0x10		/* Receiver enable bit 							*/



#define STOP_BITS_CLEAR					0x08		/* These bits are used for programming the stop bits.
 	 	 	 	 	 	 	 	 	 	 	 	 	 * 0 -> 1 Stop bit
 	 	 	 	 	 	 	 	 	 	 	 	 	 * 1 -> 2 Stop bits
 	 	 	 	 	 	 	 	 	 	 	 	 	 */

/*-------------------------------------For configuration------------------------------------------*/
#define DATA_BITS_EIGHT					0x86

#define NO_PARITY						0
#define EVEN_PARITY						0xA0
#define ODD_PARITY						0xB0



#define DISABLE_TXE_INT					~(TXEIE_TXE_INT_EN)
#define ENABLE_TXE_INT					TXEIE_TXE_INT_EN

#define DISABLE_RXNE_INT				~(RXNEIE_RXNE_INT)
#define ENABLE_RXNE_INT					RXNEIE_RXNE_INT


#define NO_INT_ENABLED					0x00
#define NO_INT_DISABLED					0xFFFFFFFF

#define ONE_STOP_BIT					0x00
#define TWO_STOP_BIT					0x08

#define BUADRATE_9600_8MHZ				51

/*--------------------------------------Functions Prototypes--------------------------------*/
extern Error_Status USART_Init();
extern Error_Status USART_Send(u8* bufferData, u32 bytesCount);
extern Error_Status USART_Recieve(u8* bufferData, u32 bytesCount);
extern Error_Status USART_setTxCbf (txCbf_t txCbf);
extern Error_Status USART_setRxCbf (rxCbf_t rxCbf);

#endif /* USART_H_ */
