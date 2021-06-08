
#include "stm32f4xx.h"
#include "veri.h"
void veri_yollaUSBTTL(const char* dizi)
{
	
	while(*dizi)
	{
	 USART3->DR=*dizi;
   while(!(USART3->SR&(1<<6)));  // TC Bit.
	 dizi++;
	}
	 	
		 
}

void veri_yollaESP8266(const char* dizi)
{
	
	while(*dizi)
	{
	 USART2->DR=*dizi;
   while(!(USART2->SR&(1<<6)));  // TC Bit.
	 dizi++;	
	}
	 	
		 
}

