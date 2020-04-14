#ifndef _H_STDTYPES_
#define _H_STDTYPES_
/******************************************/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int  u32;

typedef signed char  s8;
typedef signed short int  s16;
typedef signed long int  s32;

typedef float  f8;
typedef double  f16;
typedef long double  f32;
/*****************************************/

/****************************************/
/* Return Status for each function to indicate if it's worked correctly or not */
typedef u8 Error_Status;

#define E_OK 		0
#define E_NOK		1
/*****************************************/

/*****************************************
 if Door is opened switch will be activated and lamp will be turned on */
#define DOOROPEN        0
#define DOORCLOSED      1
/******************************************/

#endif
