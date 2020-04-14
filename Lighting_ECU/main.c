#include "STD_TYPES.h"
#include "OS.h"
#include "DoorContact.h"
#include "Left_Door.h"
#include "Right_Door.h"


void main(void) {
    RightDoor_Init();
    LeftDoor_Init();
    Sched_init();
    Sched_Start();
    while(1);
}
