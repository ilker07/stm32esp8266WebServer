 #include "stm32f4xx.h" 
#include "gpio.h"

void GPIO_Config()
{
	
	/*led 12-13-14-15*/
	RCC->AHB1ENR |=1<<3;  //D Clock Aktif.
	GPIOD->MODER  = 0x55000400; //Output modu
	GPIOD->OTYPER = 0x00000000; //Push-Pull
	GPIOD->OSPEEDR =0xAA000000; //Yuksek hiz
	/*led */
	
	
	/*Usb-ttl STM32 baglantisi icin.*/
	RCC->AHB1ENR  |= 0x00000002;		// GPIOB Clock Enable
	GPIOB->MODER  |= (1 << 21) | (1 << 23);		// AF PB10 AND PB11
	GPIOB->AFR[1] |= (1 << 8) | (1 << 9) |(1<<10);			// PB10 (uart tx)  PB11(UART RX) AF7 (USART3)
	GPIOB->AFR[1] |= (1 << 12) | (1 << 13) |(1<<14); //RX Ayari PB11
	/*Usb-ttl STM32 baglantisi icin.*/
	
	
	/*ESP8266 STM32 baglantisi icin*/
	 
	//PA2 TX ,PA3 RX   AF7
	 RCC->AHB1ENR  |= 0x00000001;		// GPIOA Clock Enable
	 GPIOA->MODER  |= (1 << 7) | (1 << 5);		// AF PA2 TX  AND PA3 RX
	 GPIOA->AFR[0] |= (1 << 8) | (1 << 9) |(1<<10);			// PA2  AF7
	 GPIOA->AFR[0] |= (1 << 12) | (1 << 13) |(1<<14); //PA3 AF7
	
	/*ESP8266 STM32 baglantisi icin*/
	
}

