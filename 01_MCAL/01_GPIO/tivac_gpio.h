/***************************************************************************
 * File name: GPIO.GPIO_H_												  
 *																		  
 *																		  
 * Description: This file contains The APIs for GPIO Driver and macros    
 * used by user                                                           
 *																		  
 * owner: Martha														  				
 * date: 26/2/2020														  
 * version 1.1															  				
 *																		  			
/**************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

/* GPIO Ports */
#define PORT_A          0x01
#define PORT_B          0x02
#define PORT_C          0x04
#define PORT_D          0x08
#define PORT_E          0x10
#define PORT_F          0x20

 /* GPIO Pins */
#define PIN0		    0
#define PIN1		    1
#define PIN2		    2
#define PIN3		    3
#define PIN4		    4
#define PIN5		    5
#define PIN6		    6
#define PIN7		    7

/*	Macros to Set and Clear Pins at write operation */
#define SET_PIN         1
#define CLEAR_PIN       0

/* Macros for pin mode -> input or output */
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

/************************************************************************
 * Function name: D_GPIO_Init
 *
 *  parameters:  Input:
 *                 Port
 *                     type: u32
                        Description: GPIO port number (PORT_A,PORT_B,PORT_C,PORT_D,PORT_E,PORT_F)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN0 .. PIN7)
 *                 Mode
 *                     type: u8
 *                     Description: GPIO pin mode (INPUT_PIN,OUTPUT_PIN)
 *
 *              Output: NA
 *              In/out: NA

 * return: E_OK, E_NOK
 * Description: a function to Enable Port, Set Pin Direction
 * and configure input pins as pull up
 ***************************************************************************/
Error_Status D_GPIO_Init(u32 Copy_u32Port, u8 Copy_u8Pin, u8 Copy_u8Mode);

/************************************************************************
 * function name: GPIO_WritePin
 *
 * parameters:  Input:
 *                Port
 *                     type: u8
                        Description: GPIO port number (PORT_A,PORT_B,PORT_C,PORT_D,PORT_E,PORT_F)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN0 .. PIN7)
 *                     type: u8
 *                 Data
 *                     type: u8
 *                     Description: data which to be written on specified pin
 *
 *              Output: NA
 *              In/out: NA
 *
 * return: E_OK, E_NOK
 * Description: a function to write data to a specific port and pin
***************************************************************************/
Error_Status D_GPIO_WritePin(u32 Copy_u32Port, u8 Copy_u8Pin, u8 Copy_u8Data);

/************************************************************************
 * function name: D_GPIO_ReadPin
 *
 * parameters:  Input:
 *                Port
 *                     type: u32
                        Description: GPIO port number (PORT_A,PORT_B,PORT_C,PORT_D,PORT_E,PORT_F)
 *                 Pin
 *                     type: u8
 *                     Description: GPIO pin number (PIN0 .. PIN7)
 *
 *              Output: NA
 *              In/out: Data
 *                     type: pointer to u8
 *                     Description: data which to be read from specified pin
 *
 * return: E_OK, E_NOK
 * Description: a function to Digital read data from a specific port and pin
***************************************************************************/
Error_Status D_GPIO_ReadPin(u32 Copy_u32Port, u8 Copy_u32Pin, u8* Copy_u32Data);

#endif
/* GPIO_H_ */
