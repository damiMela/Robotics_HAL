/*
 * DR_PLL.c
 *
 *  Created on: Dec 30, 2020
 *  Author: Damian Melamed
 */


/*!-----------INCLUDES PRIVADOS-----------------------------------------------------------------------------*/
#include <DR_h/DR_PLL.h>

/*!-----------DEFINES Y MACROS PRIVADOS---------------------------------------------------------------------*/
#define RCC_BASE             (AHB_PERIPH_BASE + 0x00001000UL)
#define RCC                	 ((RCC_t *)RCC_BASE)

#define AHB_SRAM_EN		2
#define AHB_FLITF_EN	4
#define AHB_FSMC_EN		8
#define AHB_SDIO_EN		10

/*!-----------TIPOS DE DATOS PRIVADOS-----------------------------------------------------------------------*/
typedef struct{
	uint32_t HSI_on:	1;
	uint32_t HSI_ready: 1;
	uint32_t RESERVED0: 1;
	uint32_t HSI_trim:  5;
	uint32_t ISI_calib: 8;
	uint32_t HSE_on:	1;
	uint32_t HSE_ready:	1;
	uint32_t HSE_bypass:1;
	uint32_t CSS_on:	1;
	uint32_t RESERVED1:	4;
	uint32_t PLL_on:	1;
	uint32_t PLL_ready:	1;
	uint32_t RESERVED2:	6;
} RCC_CR_t;


typedef struct{
	uint32_t SysClk_sw:		2; //SW. system clock switch
	uint32_t SysClk_sw_stat:2; //SWS system clock switch status
	uint32_t AHB_presc:		4; //HPRE. AHB preescaler
	uint32_t APB1_presc:	3; //PPRE1. APB1 low-speed preescaler
	uint32_t APB2_presc:	3; //PPRE2. APB2 high-speed preescaler
	uint32_t ADC_presc:		2; //ADCPRE. adc preescaler
	uint32_t PLL_src:		1; //PLLSRC. PLL source
	uint32_t HSE_PLL_div:	1; //PLLXTPRE. HSE dividier for
	uint32_t PLL_mult:		4; //PLLMUL. PLL multiplication factor
	uint32_t USB_presc:		1; //USBPRE. USB prescaler
	uint32_t RESERVED0:		1;
	uint32_t Clk_output:	3; //MCO. microcontroller clock output
	uint32_t RESERVED1:		5;
}RCC_CFGR_t;

typedef struct{
  __RW RCC_CR_t 	CR;
  __RW RCC_CFGR_t 	CFGR;
  __RW uint32_t 	CIR;
  __RW uint32_t 	APB2_RST;
  __RW uint32_t 	APB1_RST;
  __RW uint32_t 	AHB_EN;
  __RW uint32_t 	APB2_EN;
  __RW uint32_t 	APB1_EN;
  __RW uint32_t 	BDCR;
  __RW uint32_t 	CSR;

} RCC_t;
/*!-----------VARIABLES GLOBALES PRIVADAS-------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/

/** @brief Iniciializa y configura la entrada de clock, el PLL y los clocks de los perifericos
 *
 */
void CLK_init(){
	//mux selection
	RCC->CFGR.PLL_src = 1; //HSE as PLL source
	RCC->CFGR.SysClk_sw = 0b10; //PLL as system clk source
	while(RCC->CFGR.SysClk_sw_stat != 0b10);

	//Enable HSE
	RCC->CR.HSE_on = 1;
	while(!RCC->CR.HSE_ready);

	//configure PLL
	RCC->CFGR.HSE_PLL_div = 0; //PLL input = HSE. (si se pone '1' -> PLL input = HSE/2)
	RCC->CFGR.PLL_mult = 0b0111; //PLL mult = x9

	//enable PLL
	RCC->CR.PLL_on = 1;
	while(!RCC->CR.PLL_ready);

	//configure periferials
	RCC->CFGR.AHB_presc = 0;
	RCC->CFGR.APB1_presc = 0b100; //APB1. HSE*PLL / 2
	RCC->CFGR.APB2_presc = 0b000; //APB2. HSE*PLL

	RCC->AHB_EN |= (1 << AHB_FLITF_EN) | (1 << AHB_SRAM_EN); //SDIO y FSMC??
}



/** @brief 	Permite hablitar los clocks de los perifericos
 *  @param 	registro a escribir. USAR DEFINES APB1 y APB2
 *  @param  bit a escribir
 *  @param 	habilitacion. 1 para habilitar, 0 para deshabilitar
 */
void PCLK_setEnable(uint8_t reg, uint8_t bit, uint8_t en){
	if(reg > PCLK) return;
	if(bit > 31) return;

	if(en)
		RCC->APB1_EN |= (1 << bit);
	else
		RCC->APB1_EN &= ~(1 << bit);
}


