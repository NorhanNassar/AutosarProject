#include "STD_TYPES.h"
#include "HSwitch.h"
#include "HSwitch_cfg.h"
#include "OS.h"
#include "DIO_interface.h"

extern Switch_cfg_t Switches[SWITCHES_NUMBER];

static u8 switchState[SWITCHES_NUMBER];

Error_Status Switch_init()
{
    Error_Status loc_err = E_OK;
    u8 i;

    for(i=0;i<SWITCHES_NUMBER;i++)
    {
        loc_err |= setPinDir(Switches[i].Switch_Port, Switches[i].Switch_Pin, 1);

        if(Switches[i].SWITCH_STATE == PULL_UP)
            loc_err |= setPinValue(Switches[i].Switch_Port,Switches[i].Switch_Pin,1);
        else if(Switches[i].SWITCH_STATE == PULL_DOWN)
            loc_err |= setPinValue(Switches[i].Switch_Port,Switches[i].Switch_Pin,0);
    }
    return loc_err;
}

void HSwitch_Runnable(void)
{
    static u8 currentState[SWITCHES_NUMBER];
    static u8 prevState[SWITCHES_NUMBER]={0};
    static u8 counter[SWITCHES_NUMBER]={0};
    u8 i;

    for(i=0;i<SWITCHES_NUMBER;i++)
    {
        getPinValue(Switches[i].Switch_Port, Switches[i].Switch_Pin, (currentState+i));
        if(currentState[i]==prevState[i])
            counter[i]++;
        else
            counter[i]=0;

        if(counter[i] == 5)
        {
            counter[i] =0;
            switchState[i] = currentState[i];

        }
        prevState[i]=currentState[i];
    }

}

Error_Status Switch_getSwitchState(u8 Copy_u8SwitchNum,u8* Copy_PtrSwitchState)
{
     *Copy_PtrSwitchState = switchState[Copy_u8SwitchNum];
    return E_OK;
}

task_t HswitchTask = {&HSwitch_Runnable,25};





