#include "STD_TYPES.h"
#include "tivac_gpio.h"
#include "Lamp.h"

/* Lamp Initialization to initialize all Lamp channels at lightning system */
Error_Status Lamp_Init(void)
{
	Error_Status loc_err = E_OK;
	loc_err = D_GPIO_Init(LAMP_PORT_CH0,LAMP_PIN_CH0,LAMP_MODE_CH0);
	return loc_err;
}
/****************************************************************************/

/* Lamp_Update takes Lamp channel and status to turn lamp ON or OFF */
Error_Status Lamp_Update(u32 LAMP_CH, u8 LAMP_Status)
{
	Error_Status loc_err = E_OK;
	switch(LAMP_Status)
		{
			case L_ON:
			switch(LAMP_CH)
			{
				case LAMP_CH0:
				loc_err = D_GPIO_WritePin(LAMP_PORT_CH0,LAMP_PIN_CH0,L_ON);
				break;

				default:
				loc_err = E_NOK;
				break;
			}

			case L_OFF:
			switch(LAMP_CH)
			{
				case LAMP_CH0:
				loc_err = D_GPIO_WritePin(LAMP_PORT_CH0,LAMP_PIN_CH0,L_OFF);
				break;

				default:
				loc_err = E_NOK;
				break;
			}

			default:
			loc_err = E_NOK;
			break;
		}
		
	return loc_err;
}
