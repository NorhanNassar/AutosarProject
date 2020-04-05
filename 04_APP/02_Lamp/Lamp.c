#include "STD_TYPES.h"
#include "RTE.h"
#include "Lamp.h"

/* Lamp Initialization to initialize all Lamp channels at lightning system */
Error_Status Lamp_Init(void)
{
    return (RTE_Call_Init_Lamp());
}
/****************************************************************************/

/* Lamp_Update turns lamp ON or OFF */
Error_Status Lamp_Update()
{
    Error_Status loc_err = E_OK;
    u8 LampStatus;
    RTE_Read_Lamp_Status(&LampStatus);
	switch(LampStatus)
		{
			case L_ON:
			    RTE_Set_Lamp_Status();
			    break;
			case L_OFF:
			    RTE_Reset_Lamp_Status();
			    break;
			default:
			loc_err = E_NOK;
			break;
		}
		
	return loc_err;
}
