/*
 * manu.h
 *
 * Created: 05-Apr-23 11:50:55 PM
 *  Author: Zerconium
 */ 


#ifndef MANU_H_
#define MANU_H_

/*****************************************************************************************************************************************************************
*																		Bit manipulation macros																	 *
******************************************************************************************************************************************************************/

#define SET_BIT(REG,BIT)		(REG |= 1<<BIT)
#define RESET_BIT(REG,BIT)		(REG &=~ 1<<BIT)
#define TOOGLE_BIT(REG,BIT)		(REG ^= 1<<BIT)
#define READ_BIT(REG,BIT)		((REG>>BIT) & 1)


#endif /* MANU_H_ */