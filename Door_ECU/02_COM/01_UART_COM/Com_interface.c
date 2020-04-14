/*
 * Com_interface.c
 *
 *  Created on: Apr 13, 2020
 *      Author: Moamen
 */
#include "STD_TYPES.h"
#include "Com_interface.h"
#include "OS.h"

static u8 RX_Buffer;
static u8 TX_buffer;

static u8 startTransmition = 0;
static u8 startReceive = 0;

extern const Com_signal_cfg systemSignals[];

void Com_Start_Receive(void){
	startReceive=1;
}
void Com_Start_Transmition(void){
	startTransmition=1;
}
void Com_RX_Main_Fnc(void) {
	if (startReceive) {
		startReceive = 0;
			USART_Recieve(&RX_Buffer, 1);
	}
}
void Com_TX_Main_Fnc(void) {
	if (startTransmition) {
		startTransmition = 0;
		USART_Send(&TX_buffer, 1);
	}
}

Error_Status Com_Send_Signal(u8 SingalID, u8 Data) {
	u8 message_mask, i = 0;
	if (SingalID > MAX_SIGNALS)
		return E_NOK;
	for (i = systemSignals[SingalID].signal_start_bit;
			i <= systemSignals[SingalID].signal_end_bit; ++i) {
		message_mask |= 1 << i;
	}
	TX_buffer &= ~message_mask;
	TX_buffer |= ((Data << systemSignals[SingalID].signal_start_bit)
			& message_mask);

	return E_OK;
}
Error_Status Com_Recieve_Signal(u8 SingalID, u8* Data) {
	u8 message_mask, i = 0;
	u8 tempData = 0;
	if (SingalID > MAX_SIGNALS)
		return E_NOK;
	for (i = systemSignals[SingalID].signal_start_bit;
			i <= systemSignals[SingalID].signal_end_bit; ++i) {
		tempData |= (RX_Buffer & (1 << i));
	}
	*Data = tempData >> systemSignals[SingalID].signal_start_bit;
	return E_OK;
}

task_t const SendTask={Com_TX_Main_Fnc,50};
