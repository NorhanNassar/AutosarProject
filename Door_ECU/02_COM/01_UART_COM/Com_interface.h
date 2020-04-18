/*
 * Com_interface.h
 *
 *  Created on: Apr 13, 2020
 *      Author: Moamen
 */

#ifndef COM_INTERFACE_H_
#define COM_INTERFACE_H_

#define PDU_ID_1 		0
#define PDU_ID_2 		1
#define PDU_ID_3 		2
#define PDU_ID_4 		3


#define SIGNAL_ID_1 	0
#define SIGNAL_ID_2 	1
#define SIGNAL_ID_3 	2
#define SIGNAL_ID_4 	3
#define SIGNAL_ID_5 	4
#define SIGNAL_ID_6 	5

#define PDU_ID_OFFSET 2

#define MAX_BITS				7
#define MAX_NUM_OF_PDUS 		4
#define MAX_NUM_OF_SIGNALS 		6

typedef struct {
	u8 SignalID;
	u8 signal_start_bit;
	u8 signal_end_bit;

}Com_signal_cfg;

typedef struct {
	u8 PDU_ID;
	u8 numOfSignals;
	Com_signal_cfg systemSignals[MAX_NUM_OF_SIGNALS];
}Com_PDU_cfg;

void Com_RX_Main_Fnc(void);
void Com_TX_Main_Fnc(void);
Error_Status Com_Send_Signal(u8 SingalID,u8 Data);
Error_Status Com_Recieve_Signal(u8 SingalID,u8* Data);

#endif /* COM_INTERFACE_H_ */
