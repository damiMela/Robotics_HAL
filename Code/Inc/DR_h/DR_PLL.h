/*
 * DR_PLL.h
 *
 *  Created on: Dec 30, 2020
 *  Author: Damian Melamed
 */

#ifndef DR_H_DR_PLL_H_
#define DR_H_DR_PLL_H_

/*!-----------INCLUDES PUBLICOS-----------------------------------------------------------------------------*/
#include <System.h>
/*!-----------DEFINES Y MACROS PUBLCIAS---------------------------------------------------------------------*/
enum{PCLK1, PCLK};

/*!-----------TIPOS DE DATOS PUBLCIAS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/
//extern variables

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/
void CLK_init();
void PCLK_setEnable(uint8_t reg, uint8_t bit, uint8_t en);

#endif /* DR_H_DR_PLL_H_ */
