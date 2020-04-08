#include "STD_TYPES.h"
#include "OS.h"
#include "Dimmer.h"
#include "DoorContact.h"
#include "Left_Door.h"
#include "Right_Door.h"
#include "Lamp.h"

void main(void) {
    RightDoor_Init();
    LeftDoor_Init();
    Lamp_Init();
    Sched_init();
    Sched_Start();
    while(1);
}
