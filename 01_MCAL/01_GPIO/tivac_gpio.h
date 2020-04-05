/*
 * gpio.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Martha
 */

#ifndef GPIO_H_
#define GPIO_H_

#define PORT_A          0x01
#define PORT_B          0x02
#define PORT_C          0x04
#define PORT_D          0x08
#define PORT_E          0x10
#define PORT_F          0x20

#define PIN0		    0
#define PIN1		    1
#define PIN2		    2
#define PIN3		    3
#define PIN4		    4
#define PIN5		    5
#define PIN6		    6
#define PIN7		    7

#define SET_PIN         1
#define CLEAR_PIN       0

#define INPUT_PIN 	    0
#define OUTPUT_PIN 	    1

/* Addresses of Registers */
#define RCGCGPIO_BASE_ADDRESS       0x400FE000
#define RCGCGPIO                    *((u32 volatile*)(RCGCGPIO_BASE_ADDRESS + 0x108))
//#define RCGCGPIO                    *((u32 volatile*)(RCGCGPIO_BASE_ADDRESS + 0x608))

#define PORT_A_BASE                 0x40004000
#define PORT_A_DIR 		            *((u32 volatile*)(PORT_A_BASE + 0x400))
#define PORT_A_DATA 	            *((u32 volatile*)(PORT_A_BASE + 0x3FC))
#define PORT_A_DEN                  *((u32 volatile*)(PORT_A_BASE + 0x51C))
#define PORT_A_PUR                  *((u32 volatile*)(PORT_A_BASE + 0x510))

#define PORT_B_BASE                 0x40005000
#define PORT_B_DIR                  *((u32 volatile*)(PORT_B_BASE + 0x400))
#define PORT_B_DATA                 *((u32 volatile*)(PORT_B_BASE + 0x3FC))
#define PORT_B_DEN                  *((u32 volatile*)(PORT_B_BASE + 0x51C))
#define PORT_B_PUR                  *((u32 volatile*)(PORT_B_BASE + 0x510))

#define PORT_C_BASE                 0x40006000
#define PORT_C_DIR                  *((u32 volatile*)(PORT_C_BASE + 0x400))
#define PORT_C_DATA                 *((u32 volatile*)(PORT_C_BASE + 0x3FC))
#define PORT_C_DEN                  *((u32 volatile*)(PORT_C_BASE + 0x51C))
#define PORT_C_PUR                  *((u32 volatile*)(PORT_C_BASE + 0x510))

#define PORT_D_BASE                 0x40007000
#define PORT_D_DIR                  *((u32 volatile*)(PORT_D_BASE + 0x400))
#define PORT_D_DATA                 *((u32 volatile*)(PORT_D_BASE + 0x3FC))
#define PORT_D_DEN                  *((u32 volatile*)(PORT_D_BASE + 0x51C))
#define PORT_D_PUR                  *((u32 volatile*)(PORT_D_BASE + 0x510))
#define PORT_D_LOCK                 *((u32 volatile*)(PORT_D_BASE + 0x520))

#define PORT_E_BASE                 0x40024000
#define PORT_E_DIR                  *((u32 volatile*)(PORT_E_BASE + 0x400))
#define PORT_E_DATA                 *((u32 volatile*)(PORT_E_BASE + 0x3FC))
#define PORT_E_DEN                  *((u32 volatile*)(PORT_E_BASE + 0x51C))
#define PORT_E_PUR                  *((u32 volatile*)(PORT_E_BASE + 0x510))

#define PORT_F_BASE                 0x40025000
#define PORT_F_DIR                  *((u32 volatile*)(PORT_F_BASE + 0x400))
#define PORT_F_DATA                 *((u32 volatile*)(PORT_F_BASE + 0x3FC))
#define PORT_F_DEN                  *((u32 volatile*)(PORT_F_BASE + 0x51C))
#define PORT_F_PUR                  *((u32 volatile*)(PORT_F_BASE + 0x510))
#define PORT_F_PDR                  *((u32 volatile*)(PORT_F_BASE + 0x514))
#define PORT_F_LOCK                 *((u32 volatile*)(PORT_F_BASE + 0x520))

#define GPIOCR                      *((u32 volatile*)(PORT_F_BASE + 0x524))


/* Data that must be set to unlock the unlocked registers */
#define UNLOCK                      0x4C4F434B

/***************************************************************************/
Error_Status D_GPIO_Init(u32 Copy_u32Port, u8 Copy_u32Pin, u8 Copy_u32Mode);
Error_Status D_GPIO_WritePin(u32 Copy_u32Port, u8 Copy_u32Pin, u8 Copy_u32Data);
Error_Status D_GPIO_ReadPin(u32 Copy_u32Port, u8 Copy_u32Pin, u8* Copy_u32Data);

#endif
/* GPIO_H_ */
