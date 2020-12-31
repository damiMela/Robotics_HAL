/*
 * DR_Systick.c
 *
 *  Created on: Dec 30, 2020
 *  Author: Damian Melamed
 */


/*!-----------INCLUDES PRIVADOS-----------------------------------------------------------------------------*/
#include <DR_h/DR_Systick.h>
/*!-----------DEFINES Y MACROS PRIVADOS---------------------------------------------------------------------*/
#define SYSTICK_BASE 	(0xE000E010UL)
#define SYSTICK		((STK_t *) SYSTICK_BASE)

/*!-----------TIPOS DE DATOS PRIVADOS-----------------------------------------------------------------------*/
typedef struct{
	uint32_t STK_enable:	1;
	uint32_t TICK_int:		1;
	uint32_t CLK_SOURCE:	1;
	uint32_t RESERVED0:		13;
	uint32_t Count_flag:	1;
	uint32_t RESERVED1:		15;
} STK_ctrl_t;


typedef struct{
	__RW STK_ctrl_t STK_CTRL;
	__RW uint32_t STK_LOAD;
	__RW uint32_t STK_VAL;
	__R  uint32_t STK_CALIB;  //1ms for 9MHz  (72Mhz/8)
}STK_t;
/*!-----------VARIABLES GLOBALES PRIVADAS-------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/

/** @brief 	Inicializa el systick con interrupciones cada 1ms
 *
 */
void Systick_init(void){
	SYSTICK->STK_LOAD = SYSTICK->STK_CALIB * 8;  //tick cada 1ms
	SYSTICK->STK_CTRL.CLK_SOURCE = 0; // Freq = Processor Clock (AHB)
	SYSTICK->STK_VAL = 0;
	SYSTICK->STK_CTRL.TICK_int = 1;
	SYSTICK->STK_CTRL.STK_enable = 1;
}

/** @brief 	Systick handler
 *
 */
void SysTick_Handler(void){
	//timer run, scheduler
}
