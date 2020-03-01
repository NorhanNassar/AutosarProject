#ifndef _LAMP_H__
#define _LAMP_H__

/* Define each lamp channel in the system */
#define LAMP_CH0            0

/* Configurations for each lamp in the system */
#define LAMP_PORT_CH0		PORT_F
#define LAMP_PIN_CH0		1
#define LAMP_MODE_CH0		OUTPUT_PIN

/* L_ON to turn Lamp ON and L_OFF to turn it off */
#define L_ON				1
#define L_OFF				0

/*************************************************/
Error_Status Lamp_Init(void);
Error_Status Lamp_Update(u32 LAMP_CH, u8 LAMP_Status);

#endif
