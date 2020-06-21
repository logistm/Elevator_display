#ifndef MATRIXCHARACTERS_H_
#define MATRIXCHARACTERS_H_

#include "main.h"

void LCDWriteCharacter_small(uint8_t data1[16][8], uint8_t data2[16][8]);
void LCDWriteCharacter(uint8_t data1[16][8], uint8_t data2[16][8], uint8_t data3[16][8]);
void LCDWriteCharacterShift(uint8_t data[16][8]);
void LCDColumnON(uint8_t i);
void LCDColumnOFF(uint8_t j);
void LCDClear(void);
void LCDLatch(uint8_t delay);
void LCDFirstZero(void);
void LCDDemo(uint8_t number);

#endif /* MATRIXCHARACTERS_H_ */
