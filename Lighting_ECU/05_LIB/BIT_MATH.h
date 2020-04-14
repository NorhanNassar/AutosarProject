#define SET_BIT(Port,Bit_Num)		Port |= ( 1<<Bit_Num )

#define GET_BIT(Port,Bit_Num)		( (Port>>Bit_Num) &1 )

#define CLR_BIT(Port,Bit_Num)		Port &= ( ~(1<<Bit_Num) )

#define TOG_BIT(Port,Bit_Num)		Port ^= (1<<Bit_Num)

