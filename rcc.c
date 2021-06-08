
#include "stm32f4xx.h" 
#include "rcc.h"
void RCC_Config()
{
	 
	//	HSI OFF HSE ON
	RCC->CR &=~(1<<0);//hsi off yap
	
	RCC->CR |= 0x00010000;	// HSEON
	while(!(RCC->CR & 0x00020000));	// HSEON Ready Flag wait
	
	
	
	RCC->APB1ENR |=RCC_APB1ENR_PWREN;
	PWR->CR |=PWR_CR_VOS;
	
	

	RCC->PLLCFGR = 0x04402A04; //0040 tu..!!!!!!!!!!!!!!!!!!!!!!!!!  Eski:0x04402A04  Yeni:0x04401504
	RCC->CR |= 0x01000000;			// PLL On
	while(!(RCC->CR & (1<<25)));	// /pll bayrak kontolu.
	
	
	RCC->CFGR |= 0x00000000;		// AHB Prescaler 1   
	RCC->CFGR |= 0x00009400;		// APB1 Prescaler 4  APB2 Prescaler 2   Eski: 0x00009400  Yeni:0x00009000       
	
	
	FLASH->ACR = 0x00000605;  //5 ONEMLI
	RCC->CFGR |= 0x00000002; //Sistem PLL icin
	while(!(RCC->CFGR & (1<<1)));	// /pll bayrak kontolu.
	
	RCC->CIR |=1<<18; //Ready Bayraklari silindi.
	RCC->CIR |=1<<19;
	RCC->CIR |=1<<20;

}

