/*
 * Com_interface.c
 *
 *  Created on: Apr 13, 2020
 *      Author: Moamen
 */
#include "STD_TYPES.h"
#include "Com_interface.h"
#include "Com_PCcfg.h"
#include "USART.h"
#include "OS.h"

static u8 RX_Buffer[MAX_NUM_OF_SIGNALS];
static u8 TX_Buffer[MAX_NUM_OF_SIGNALS];

static u8 txdataBuffer;

extern const Com_PDU_cfg systemPDUs[];

void Com_RX_Main_Fnc(void) {
	u8 message_mask = 0xFF, frame[NUM_OF_PDUS], PDU_ID, Singal_ID, tempData = 0;
	USART_Recieve(frame, NUM_OF_PDUS);
	for (PDU_ID = 0; PDU_ID < NUM_OF_PDUS; ++PDU_ID) {
		for (Singal_ID = 0; Singal_ID < systemPDUs[PDU_ID].numOfSignals;
				++Singal_ID) {
			message_mask =
					message_mask
							>> systemPDUs[PDU_ID].systemSignals[Singal_ID].signal_start_bit;
			message_mask =
					message_mask
							<< systemPDUs[PDU_ID].systemSignals[Singal_ID].signal_start_bit;
			message_mask =
					message_mask
							<< (MAX_BITS
									- systemPDUs[PDU_ID].systemSignals[Singal_ID].signal_end_bit);
			message_mask =
					message_mask
							>> (MAX_BITS
									- systemPDUs[PDU_ID].systemSignals[Singal_ID].signal_end_bit);
			message_mask = message_mask << PDU_ID_OFFSET; /*assign the first 2 bit to pdu id*/
			tempData = frame[PDU_ID] & message_mask;
			RX_Buffer[Singal_ID] =
					tempData
							>> (systemPDUs[PDU_ID].systemSignals[Singal_ID].signal_start_bit
									+ PDU_ID_OFFSET);
		}
	}
}
void Com_TX_Main_Fnc(void) {
	u8 message_mask = 0xFF, frame[NUM_OF_PDUS], PDU_ID, Singal_ID;

	for (PDU_ID = 0; PDU_ID < NUM_OF_PDUS; ++PDU_ID) {
		frame[PDU_ID] = PDU_ID;
		for (Singal_ID = 0; Singal_ID < systemPDUs[PDU_ID].numOfSignals;
				++Singal_ID) {
			/*mask to clear desired data bits in the current PDU frame*/
			message_mask =
					message_mask
							>> systemPDUs[PDU_ID].systemSignals[Singal_ID].signal_start_bit;
			message_mask =
					message_mask
							<< systemPDUs[PDU_ID].systemSignals[Singal_ID].signal_start_bit;
			message_mask =
					message_mask
							<< (MAX_BITS
									- systemPDUs[PDU_ID].systemSignals[Singal_ID].signal_end_bit);
			message_mask =
					message_mask
							>> (MAX_BITS
									- systemPDUs[PDU_ID].systemSignals[Singal_ID].signal_end_bit);
			message_mask = message_mask << PDU_ID_OFFSET; /*assign the first 2 bit to pdu id*/

			frame[PDU_ID] &= ~(message_mask);
			frame[PDU_ID] |=
					(message_mask
							& TX_Buffer[Singal_ID]
									<< (systemPDUs[PDU_ID].systemSignals[Singal_ID].signal_start_bit
											+ PDU_ID_OFFSET));
		}

	}
	USART_Send(frame, NUM_OF_PDUS);
}

Error_Status Com_Send_Signal(u8 SignalID, u8 Data) {
	if (SignalID > MAX_NUM_OF_SIGNALS)
		return E_NOK;
	TX_Buffer[SignalID] = Data;
	return E_OK;
}
Error_Status Com_Recieve_Signal(u8 SignalID, u8* Data) {
	if (SignalID >= MAX_NUM_OF_SIGNALS && Data)
		return E_NOK;
	*Data = RX_Buffer[SignalID];
	return E_OK;
}

task_t const SendTask = { Com_TX_Main_Fnc, 50 };
