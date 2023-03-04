/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    Bit math lib
* Module :      Common Module
* Description:  Bit manipulations
* REV:  
* DATE:
*	Autor: M. Samy
*
************************************************************************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REGISTER,BIT) 			  REGISTER |= (1<<BIT)
#define CLEAR_BIT(REGISTER,BIT) 		  REGISTER &=~(1<<BIT)
#define TOGGLE_BIT(REGISTER,BIT) 		  REGISTER ^= (1<<BIT)
#define GET_BIT(REGISTER,BIT) 			  ((REGISTER>>BIT)&1)

#endif /* COMMON_BIT_MATH_H_ */
