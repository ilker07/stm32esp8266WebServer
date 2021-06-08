


#include "stm32f4xx.h"
#include "usart.h"

void USART_Config()
{
	/*Baud hesabi*/
	
	//42 000 000 /(9600 *16) =273.4375//
	//0.4375 * 16 =7
	//273  ==> 0x111  
	// 111 + 7  = 0x1117
	
	/*Baud hesabi*/
	/*USART2 Ayarlar*/
	RCC->APB1ENR |= 1 << 17;//USART2 Aktif
	USART2->CR1 |= 1 << 2;		// Rx Aktif
	USART2->CR1 |= 1 << 3;		// Tx Aktif
	USART2->BRR = 0x1117;		// BaudRate 9600
	USART2->CR1 |=1<<5;//RX INTERRUPT
	//NVIC->ISER[1] =1<<6;//USART2 Kesme
	USART2->CR1 |= 1 << 13;		// Usart2 Aktif
	
	/*USART2 Ayarlar*/
	
	
  /*USART3 Ayarlar*/
	RCC->APB1ENR |= 1 << 18;//USART3 Aktif
	USART3->CR1 |= 1 << 3;		// Tx Aktif
	USART3->BRR = 0x1117;		// BaudRate 9600
	USART3->CR1 |= 1 << 13;		// Usart3 Aktif
	/*USART3 Ayarlar*/
	
}

