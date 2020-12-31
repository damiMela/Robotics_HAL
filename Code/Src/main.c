/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Damian Melamed
 * @brief          : Main program
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <DR_h/DR_GPIO.h>
#include <DR_h/DR_PLL.h>
#include <DR_h/DR_Systick.h>


int main(void)
{
	CLK_init();
	Systick_init();

	while(1){
		//TODO: everything
	}

}
