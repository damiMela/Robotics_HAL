/*
 * System.h
 *
 *  Created on: 30 dic. 2020
 *      Author: usuario
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

typedef	unsigned int		uint32_t;
typedef	int					int32_t;
typedef	short unsigned int	uint16_t;
typedef	short int			int16_t;
typedef	unsigned char		uint8_t ;
typedef	char				int8_t;


#define     __R             volatile const 	//< solo lectura
#define 	__W     		volatile 		//< solo escritura
#define 	__RW            volatile 		//< lectura / escritura



#define PERIPH_BASE           0x40000000UL /*!< Peripheral base address in the alias region */

#define APB1_PERIPH_BASE       PERIPH_BASE
#define APB2_PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB_PERIPH_BASE        (PERIPH_BASE + 0x00020000UL)



#endif /* SYSTEM_H_ */
