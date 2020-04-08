#include "std_types.h"
#include "BIT_MATH.h"

Error_Status Timer0_voidInit(void);
Error_Status Timer0_voidSetCallBack(void(*Copy_pvCallBackPtr)(void));
Error_Status Timer0_voidSetTime(u32 Copy_u32Time);
