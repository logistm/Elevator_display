#ifndef SPI_H_
#define SPI_H_

void SPI3InitGPIO(void);
void SPI3Init(void);
uint8_t SPI3SendData(uint16_t* data);

#endif
