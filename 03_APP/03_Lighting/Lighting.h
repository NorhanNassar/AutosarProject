#ifndef _LIGHTNING_H__
#define _LIGHTNING_H__

/* Defines every Lighting channel
 * Channel 0 for Lamp channel 0*/
#define LIGHTING_CH0    LAMP_CH0

#define LIGHT_ON        1
#define LIGHT_OFF       0

Error_Status Lighting_Init(void);
Error_Status Lighting_Control(u8 Copy_u8LampStatus);

#endif
