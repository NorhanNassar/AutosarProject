#ifndef HSWITCH_H_
#define HSWITCH_H_

typedef     u8  SWITCH_STATE;
#define     FLOATING                2
#define     PULL_UP                 1
#define     PULL_DOWN               0


/* Structure to each switch                                                                 */
/* It contains:
 * Switch Number, Switch Pin, Switch Port, Switch state: PULL_UP,PULL_DOWN,FLAOTING         */
typedef struct
{
    u32 Switch_Port;                                /* PORTA to PORTG                       */
    u16 Switch_Pin;                                 /* GPIO_PIN0 to GPIO_PIN15              */
    u16 Switch_Num;                                 /* Switch_0 to Switch_15 or more
                                                     * if you add some in cfg.h file        */
    u8 SWITCH_STATE;                                /* PULL_UP or PULL_DOWN or FLAOTING     */
}Switch_cfg_t;

/******************************************************************************************/
/* Description: This API shall initialize all Switches at configuration file to be Input  */
/* Pull up or pull down for each port                                                     */
/******************************************************************************************/
extern Error_Status Switch_init(void);

/*****************************************************************************************/
/* Description: This API shall check if a certain switch is pressed or not               */
/* Copy_PtrState -> pointer to switch state                                              */
/*****************************************************************************************/
extern Error_Status Switch_getSwitchState(u8 Copy_u8SwitchNum,u8* Copy_PtrSwitchState);

/*****************************************************************************************/
/* Task Runnable every given periodicity                                                 */
/* to check if Switches are pressed or not                                               */
/*****************************************************************************************/
extern void HSwitch_Runnable(void);


#endif /* HSWITCH_H_ */



#endif /* DOORSENSOR_H_ */
