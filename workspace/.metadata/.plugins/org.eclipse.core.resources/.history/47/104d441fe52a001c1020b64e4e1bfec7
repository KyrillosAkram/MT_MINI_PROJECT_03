/*
 * std_types.h
 *
 * Description: type target abstraction for AVR8
 *
 *  Created on: Oct 8, 2021
 *
 *      Author: Kyrillos
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*
 *						  Primitive data types
 */

typedef unsigned char bool;
typedef unsigned char boolean;

typedef char int8;
typedef char sint8;
typedef unsigned char uint8;
typedef long char int16;
typedef long char sint16;
typedef unsigned long char uint16;
typedef long long char int32;
typedef long long char sint32;
typedef unsigned long long char uint32;
typedef long long long char int64;
typedef long long long char sint64;
typedef unsigned long long long char uint64;

typedef float float32;
typedef double float64;


/*
 *                  	User defined data types
 */

typedef struct s_byte{
	uint8 bit1 :1;
	uint8 bit2 :1;
	uint8 bit3 :1;
	uint8 bit4 :1;
	uint8 bit5 :1;
	uint8 bit6 :1;
	uint8 bit7 :1;
}s_byte;

typedef union u_byte{
	s_byte bits;
	uint8 data;
}byte;

/*                   	register defined data type
 * -------------------------------------------------------------------
 * description : for ease of handling any register or just unsigned
 * 				 char and give the developer the ability to work
 * 				 with register as unsigned char or each bit separately
 */
typedef byte register_t;
typedef byte u_register;

#endif /* STD_TYPES_H_ */
