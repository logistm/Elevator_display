#ifndef INPUT_H_
#define INPUT_H_

#include "main.h"

#define LEVEL0				(31u)
#define LEVEL1				(30u)
#define LEVEL2				(29u)
#define LEVEL3				(28u)
#define LEVEL4				(27u)
#define LEVEL5				(26u)
#define LEVEL6				(25u)
#define LEVEL7				(24u)
#define LEVEL8				(23u)
#define LEVEL9				(22u)
#define LEVEL10				(21u)
#define LEVEL11				(20u)
#define LEVEL12				(19u)
#define LEVEL13				(18u)
#define LEVEL14				(17u)
#define LEVEL15				(16u)
#define LEVEL16				(15u)
#define LEVEL17				(14u)
#define LEVEL18				(13u)
#define LEVEL19				(12u)
#define LEVEL20				(11u)
#define LEVEL21				(10u)
#define LEVEL22				(9u)
#define LEVEL23				(8u)
#define LEVEL24				(7u)
#define LEVEL25				(6u)
#define LEVEL26				(5u)
#define LEVEL27				(4u)
#define LEVEL28				(3u)
#define LEVEL29				(2u)
#define LEVEL30				(1u)
#define LEVEL31				(0u)

#define ARROW_UP			(1u)
#define ARROW_DOWN			(2u)
#define ARROW_NONE			(3u)

uint8_t ReadBinaryInputs(void);
uint8_t ReadArrowInputs(void);
void WriteBinaryData(uint8_t result, uint8_t arrow, uint8_t counter);
void WriteBinaryDataSmall(uint8_t result, uint8_t arrow, uint8_t counter);

#endif /* INPUT_H_ */
