/*
 * Com_interface_lcfg.h
 *
 *  Created on: Apr 13, 2020
 *      Author: Moamen
 */

#include "STD_TYPES.h"
#include "Com_interface.h"
#include "Com_PCcfg.h"

const Com_PDU_cfg systemPDUs[MAX_NUM_OF_PDUS] = {
		/*
		 *PDU_ID , Num of signals ,  {SignalID    ,  start bit , end bit}, ...
		 */
		{PDU_ID_1, 1			  ,  {SIGNAL_ID_1 ,  0         , 0}}
};
