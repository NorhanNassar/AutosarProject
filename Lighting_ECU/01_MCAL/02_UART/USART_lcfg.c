/*
 * USART_cfg.c
 *
 *  Created on: Mar 30, 2020
 *      Author: Norhan Nassar
 */

#include "STD_TYPES.h"
#include "USART.h"

extern USART_Init_Cfg_t USART_Init_Cfg = {
		BUADRATE_9600_8MHZ,
		DATA_BITS_EIGHT,
		NO_PARITY,
		(ENABLE_TXE_INT | ENABLE_RXNE_INT),
		ONE_STOP_BIT,
};
