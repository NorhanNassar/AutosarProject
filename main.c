#include "./04_LIB/STD_TYPES.h"
#include "./03_APP/01_LeftDoor/Left_Door.h"
#include "./03_APP/02_RightDoor/Right_Door.h"
#include "./03_APP/03_Lighting/Lighting.h"

void main(void) {
    u8 DoorStatus_L;
    u8 DoorStatus_R;

    RightDoor_Init();
    leftDoor_Init();
    Lighting_Init();
    while(1){
        RightDoor_ReadStatus(&DoorStatus_R);
        LeftDoor_ReadStatus(&DoorStatus_L);
        if( (DoorStatus_L == DOOROPEN) || (DoorStatus_R == DOOROPEN) )
            Lighting_Control(LIGHT_ON);
        else
            Lighting_Control(LIGHT_OFF);
    }
}
