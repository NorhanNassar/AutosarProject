#include "STD_TYPES.h"
#include "Left_Door.h"
#include "Right_Door.h"
#include "Lightning.h"
#include "DoorSensor.h"
#include "Lamp.h"

void main(void) {
    u8 DoorStatus_L;
    u8 DoorStatus_R;

    RightDoor_Init();
    leftDoor_Init();
    Lamp_Init();
    while(1){
        RightDoor_ReadStatus(&DoorStatus_R);
        LeftDoor_ReadStatus(&DoorStatus_L);
        DoorSensor_ReadStatus();
        Lighting_Control();
        Lamp_Update();
    }
}
