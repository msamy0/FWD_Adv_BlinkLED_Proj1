/************************************************************************************************************************
* FILE DESCRIPTION
* -----------------------------------------------------------------------------------------------------------------------
* File name:    Standard Types
* Module :      Common Module
* Description:  
* REV:          1.0
* DATE:
*	Autor: M. Samy
************************************************************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_



typedef unsigned char              uint8;
typedef unsigned short int         uint16;
typedef unsigned int               uint32;
typedef unsigned long long         uint64;
typedef signed char                sint8;
typedef signed short int           sint16;
typedef signed int                 sint32;

typedef enum
{
	NOK,
	OK
} STD_DriverErrHandlerType;



#define STD_HIGH                   0x01
#define STD_LOW                    0x00
#define NULL                       ((void *)0)

#endif /* STD_TYPES_H_ */
