/*
 * Bit_math.h
 *
 * Created: 11/27/2021 12:17:48 PM
 *  Author: hosam
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG , BIT) ( REG |= (1 << BIT) )
#define CLEAR_BIT(REG , BIT) ( REG &= ~( 1 << BIT) )
#define TOGGLE_BIT(REG , BIT) ( REG ^= (1 << BIT) )
#define GET_BIT(REG, BIT) ( (REG>>BIT) & 0X01 )

#endif /* BIT_MATH_H_ */