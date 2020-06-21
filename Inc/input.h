#ifndef INPUT_H_
#define INPUT_H_

#include "main.h"

#define LEVEL0				31
#define LEVEL1				30
#define LEVEL2				29
#define LEVEL3				28
#define LEVEL4				27
#define LEVEL5				26
#define LEVEL6				25
#define LEVEL7				24
#define LEVEL8				23
#define LEVEL9				22
#define LEVEL10				21
#define LEVEL11				20
#define LEVEL12				19
#define LEVEL13				18
#define LEVEL14				17
#define LEVEL15				16
#define LEVEL16				15
#define LEVEL17				14
#define LEVEL18				13
#define LEVEL19				12
#define LEVEL20				11
#define LEVEL21				10
#define LEVEL22				9
#define LEVEL23				8
#define LEVEL24				7
#define LEVEL25				6
#define LEVEL26				5
#define LEVEL27				4
#define LEVEL28				3
#define LEVEL29				2
#define LEVEL30				1
#define LEVEL31				0

#define ARROW_UP			1
#define ARROW_DOWN			2
#define ARROW_NONE			3

uint8_t ReadBinaryInputs(void);
uint8_t ReadArrowInputs(void);
void WriteBinaryData(uint8_t result, uint8_t arrow, uint8_t counter);

#endif /* INPUT_H_ */
