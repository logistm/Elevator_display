#include "stm32l4xx_hal.h"
#include "spi.h"

/*
EXAMPLE:
SPI->CR1 &= ~SPI_CR1_BR; // Clear SPI baud rate bits
SPI->CR1 |= prescaler; // Set SPI baud rate bits
SPI->CR1 |= SPI_CR1_SPE; // Enable the specified SPI peripheral
*/

// SPI3_MOSI - PB5
// SPI3 SCK - PB3

void SPI3InitGPIO()
{
	RCC->APB1ENR1 |= RCC_APB1ENR1_PWREN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; // IO port B clock enable
	GPIOB->MODER |= GPIO_MODER_MODE3_1 | GPIO_MODER_MODE5_1;     //set PB3 & PB5 as altenrate function
	GPIOB->MODER &= ~(GPIO_MODER_MODE3_0 | GPIO_MODER_MODE5_0);
	GPIOB->AFR[0] |= GPIO_AFRL_AFSEL3_1 | GPIO_AFRL_AFSEL3_2 | GPIO_AFRL_AFSEL5_1 | GPIO_AFRL_AFSEL5_2;
	GPIOB->AFR[1] &= ~(GPIO_AFRL_AFSEL3_0 | GPIO_AFRL_AFSEL3_3 | GPIO_AFRL_AFSEL5_0 | GPIO_AFRL_AFSEL5_3); //set alternate function for AF6, from Table 16 of basic datasheet
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT3 | GPIO_OTYPER_OT5);	 //set as reset ("0") in idle state
	GPIOB->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR3_0 | GPIO_OSPEEDER_OSPEEDR5_0);
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3_1 | GPIO_OSPEEDER_OSPEEDR5_1; // set "High" speed for speed
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPD3  | GPIO_PUPDR_PUPD5); // no push UP/DOWN
	GPIOB->PUPDR |= GPIO_PUPDR_PUPD3_1  | GPIO_PUPDR_PUPD5_1;
}

void SPI3Init()
{
	SPI3InitGPIO();
	RCC->APB1ENR1 |= RCC_APB1ENR1_SPI3EN; // enable SPI clock
	SPI3->CR1 |= SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE  | SPI_CR1_MSTR;//| SPI_CR1_LSBFIRST
	SPI3->CR1 &= ~(SPI_CR1_CRCEN | SPI_CR1_SSM | SPI_CR1_CPHA | SPI_CR1_CPOL | SPI_CR1_BR | SPI_CR1_RXONLY);
	SPI3->CR2 |= SPI_CR2_DS | SPI_CR2_SSOE;
	SPI3->CR2 &= ~(SPI_CR2_FRF | SPI_CR2_NSSP);
	SPI3->CR1 |=SPI_CR1_SPE;
}

 uint8_t SPI3SendData(uint16_t *data)
{
	SPI3->DR = *data;

	while (!(SPI3->SR & SPI_FLAG_TXE));
	while (SPI3->SR & SPI_FLAG_BSY);

	if (SPI3->SR & SPI_FLAG_OVR)
	{
		return 1;
	}
	else if(SPI3->SR & SPI_FLAG_MODF)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
