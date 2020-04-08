#include "STD_TYPES.h"
#include "OS.h"
#include "RTE.h"
#include "Dimmer.h"


void Dimmer_Runnable()
{
  u8 DoorStatus;
  RTE_Read_Door_Status(&DoorStatus);

  if(DoorStatus==DOORCLOSED)
      RTE_Write_Lamp_Status(LIGHT_OFF);
  else if(DoorStatus==DOOROPEN)
      RTE_Write_Lamp_Status(LIGHT_OFF);

}

task_t DimmerTask = {&Dimmer_Runnable,50};

