/*
 * Com_interface.h
 *
 *  Created on: Apr 13, 2020
 *      Author: Moamen
 */

#ifndef COM_INTERFACE_H_
#define COM_INTERFACE_H_

#define SIGNAL_ID_1 	0
#define SIGNAL_ID_2 	1
#define SIGNAL_ID_3 	2
#define SIGNAL_ID_4 	3
#define SIGNAL_ID_5 	4
#define SIGNAL_ID_6 	5
#define SIGNAL_ID_7 	6
#define SIGNAL ID_8		7

#define MAX_BITS		7
#define MAX_SIGNALS 	8

typedef struct {
	u8 signal_start_bit;
	u8 signal_end_bit;
}Com_signal_cfg;

void Com_Start_Receive(void);
void Com_Start_Transmition(void);
void Com_RX_Main_Fnc(void);
void Com_TX_Main_Fnc(void);
Error_Status Com_Send_Signal(u8 SingalID,u8 Data);
Error_Status Com_Recieve_Signal(u8 SingalID,u8* Data);

#endif /* COM_INTERFACE_H_ */
