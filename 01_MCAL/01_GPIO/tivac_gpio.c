/*
 * gpio.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Martha
 */
#include "STD_TYPES.h"
#include "tivac_gpio.h"

/* Enable Port, Set Pin Direction and configure input pins as pull up */
Error_Status D_GPIO_Init(u32 Copy_u32Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
    Error_Status Local_Error = E_OK;

    switch (Copy_u32Port)
    {

    case PORT_A:
        RCGCGPIO |= PORT_A;
        if (Copy_u8Mode == OUTPUT_PIN)
        {
            PORT_A_DEN |= (0x01 << Copy_u8Pin);
            PORT_A_DIR |= (0x01 << Copy_u8Pin);

        }
        else if (Copy_u8Mode == INPUT_PIN)
        {
            PORT_A_DEN |= (0x01 << Copy_u8Pin);
            PORT_A_DIR &= (~(0x01 << Copy_u8Pin));
            PORT_A_PUR |= (1 << Copy_u8Pin);
        }
        else
        {
            Local_Error = E_NOK;
        }

        break;

    case PORT_B:
        RCGCGPIO |= PORT_B;
        if (Copy_u8Mode == OUTPUT_PIN)
        {
            PORT_B_DEN |= (0x01 << Copy_u8Pin);
            PORT_B_DIR |= (0x01 << Copy_u8Pin);

        }
        else if (Copy_u8Mode == INPUT_PIN)
        {
            PORT_B_DEN |= (0x01 << Copy_u8Pin);
            PORT_B_DIR &= (~(0x01 << Copy_u8Pin));
            PORT_B_PUR |= (1 << Copy_u8Pin);
        }
        else
        {
            Local_Error = E_NOK;
        }

        break;

    case PORT_C:
        RCGCGPIO |= PORT_C;
        if (Copy_u8Mode == OUTPUT_PIN)
        {
            PORT_C_DEN |= (0x01 << Copy_u8Pin);
            PORT_C_DIR |= (0x01 << Copy_u8Pin);
        }
        else if (Copy_u8Mode == INPUT_PIN)
        {
            PORT_C_DEN |= (0x01 << Copy_u8Pin);
            PORT_C_DIR &= (~(0x01 << Copy_u8Pin));
            PORT_C_PUR |= (1 << Copy_u8Pin);
        }
        else
        {
            Local_Error = E_NOK;
        }

        break;

    case PORT_D:
        RCGCGPIO |= PORT_D;
        if (Copy_u8Mode == OUTPUT_PIN)
        {
            PORT_D_LOCK = UNLOCK;
            PORT_D_DEN |= (0x01 << Copy_u8Pin);
            PORT_D_DIR |= (0x01 << Copy_u8Pin);
        }
        else if (Copy_u8Mode == INPUT_PIN)
        {
            PORT_D_LOCK = UNLOCK;
            PORT_D_DEN |= (0x01 << Copy_u8Pin);
            PORT_D_DIR &= (~(0x01 << Copy_u8Pin));
            PORT_D_PUR |= (1 << Copy_u8Pin);
        }
        else
        {
            Local_Error = E_NOK;
        }

        break;

    case PORT_E:
        RCGCGPIO |= PORT_E;
        if (Copy_u8Mode == OUTPUT_PIN)
        {
            PORT_E_DEN |= (0x01 << Copy_u8Pin);
            PORT_E_DIR |= (0x01 << Copy_u8Pin);
        }
        else if (Copy_u8Mode == INPUT_PIN)
        {
            PORT_E_DEN |= (0x01 << Copy_u8Pin);
            PORT_E_DIR &= (~(0x01 << Copy_u8Pin));
            PORT_E_PUR |= (1 << Copy_u8Pin);
        }
        else
        {
            Local_Error = E_NOK;
        }

        break;

    case PORT_F:
        RCGCGPIO |= PORT_F;
        if (Copy_u8Mode == OUTPUT_PIN)
        {
            PORT_F_LOCK = UNLOCK;
            PORT_F_DEN |= (0x01 << Copy_u8Pin);
            PORT_F_DIR |= (0x01 << Copy_u8Pin);
        }
        else if (Copy_u8Mode == INPUT_PIN)
        {
            PORT_F_LOCK = UNLOCK;
            PORT_F_DEN |= (0x01 << Copy_u8Pin);
            PORT_F_DIR &= (~(0x01 << Copy_u8Pin));
            PORT_F_PUR |= (0x01 << Copy_u8Pin);
        }
        else
        {
            Local_Error = E_NOK;
        }

        break;
    default:
        Local_Error = E_NOK;
        break;
    }
    return Local_Error;
}
/*********************************************************
 Read Pin state from GPIODATA Register */
Error_Status D_GPIO_ReadPin(u32 Copy_u32Port, u8 Copy_u8Pin, u8* Copy_u8Data)
{
    Error_Status Local_Error = E_OK;
    switch (Copy_u32Port)
    {
    case PORT_A:
        *Copy_u8Data = (PORT_A_DATA >> Copy_u8Pin) & 0x01;
        break;

    case PORT_B:
        *Copy_u8Data = (PORT_B_DATA >> Copy_u8Pin) & 0x01;
        break;

    case PORT_C:
        *Copy_u8Data = (PORT_C_DATA >> Copy_u8Pin) & 0x01;
        break;

    case PORT_D:
        *Copy_u8Data = (PORT_D_DATA >> Copy_u8Pin) & 0x01;
        break;

    case PORT_E:
        *Copy_u8Data = (PORT_E_DATA >> Copy_u8Pin) & 0x01;
        break;

    case PORT_F:
        *Copy_u8Data = (PORT_F_DATA >> Copy_u8Pin) & 0x01;
        break;
    default:
        Local_Error = E_NOK;
        break;
    }
    return Local_Error;
}
/**************************************************************/
/* Write Pin State at GPIODATA Register */
Error_Status D_GPIO_WritePin(u32 Copy_u32Port, u8 Copy_u8Pin,u8 Copy_u8Data)
{
    Error_Status Local_Error = E_OK;
    switch (Copy_u32Port)
    {
    case PORT_A:
        if (Copy_u8Data == SET_PIN)
        {
            PORT_A_DATA |= (1 << Copy_u8Pin);
        }
        else if (Copy_u8Data == CLEAR_PIN)
        {
            PORT_A_DATA &= (~(1 << Copy_u8Pin));
        }
        else
        {
            Local_Error = E_NOK;
        }
        break;

    case PORT_B:
        if (Copy_u8Data == SET_PIN)
        {
            PORT_B_DATA |= (1 << Copy_u8Pin);

        }
        else if (Copy_u8Data == CLEAR_PIN)
        {
            PORT_B_DATA &= (~(1 << Copy_u8Pin));

        }
        else
        {
            Local_Error = E_NOK;
        }
        break;

    case PORT_C:
        if (Copy_u8Data == SET_PIN)
        {
            PORT_C_DATA |= (1 << Copy_u8Pin);

        }
        else if (Copy_u8Data == CLEAR_PIN)
        {
            PORT_C_DATA &= (~(1 << Copy_u8Pin));

        }
        else
        {
            Local_Error = E_NOK;
        }
        break;

    case PORT_D:
        if (Copy_u8Data == SET_PIN)
        {
            PORT_D_DATA |= (1 << Copy_u8Pin);

        }
        else if (Copy_u8Data == CLEAR_PIN)
        {
            PORT_D_DATA &= (~(1 << Copy_u8Pin));

        }
        else
        {
            Local_Error = E_NOK;
        }
        break;

    case PORT_E:
        if (Copy_u8Data == SET_PIN)
        {
            PORT_E_DATA |= (1 << Copy_u8Pin);

        }
        else if (Copy_u8Data == CLEAR_PIN)
        {
            PORT_E_DATA &= (~(1 << Copy_u8Pin));

        }
        else
        {
            Local_Error = E_NOK;
        }
        break;

    case PORT_F:
        if (Copy_u8Data == SET_PIN)
        {
            PORT_F_DATA |= (1 << Copy_u8Pin);

        }
        else if (Copy_u8Data == CLEAR_PIN)
        {
            PORT_F_DATA &= (~(1 << Copy_u8Pin));

        }
        else
        {
            Local_Error = E_NOK;
        }
        break;
    default:
        Local_Error = E_NOK;
        break;
    }
    return Local_Error;
}
