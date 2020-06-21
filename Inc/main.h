#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

//#define MATRIX_SMALL
#define MATRIX_BIG

#include "stm32l4xx_hal.h"
#include "spi.h"
#include "matrixCharacters.h"

void Error_Handler(void);

#define LED_Pin GPIO_PIN_10
#define LED_GPIO_Port GPIOA
#define BLANK_Pin GPIO_PIN_4
#define BLANK_GPIO_Port GPIOB
#define LATCH_Pin GPIO_PIN_6
#define LATCH_GPIO_Port GPIOB

#ifdef MATRIX_BIG
#define STUP8_Port GPIOB
#define STUP7_Port GPIOB
#define STUP6_Port GPIOB
#define STUP5_Port GPIOB
#define STUP4_Port GPIOB
#define STUP3_Port GPIOB
#define STUP2_Port GPIOB
#define STUP1_Port GPIOB

#define STUP8 GPIO_PIN_8
#define STUP7 GPIO_PIN_9
#define STUP6 GPIO_PIN_10
#define STUP5 GPIO_PIN_11
#define STUP4 GPIO_PIN_12
#define STUP3 GPIO_PIN_13
#define STUP2 GPIO_PIN_14
#define STUP1 GPIO_PIN_15

#endif

#ifdef MATRIX_SMALL
#define STUP1_Port GPIOA
#define STUP2_Port GPIOA
#define STUP3_Port GPIOB
#define STUP4_Port GPIOB
#define STUP5_Port GPIOB
#define STUP6_Port GPIOB
#define STUP7_Port GPIOB
#define STUP8_Port GPIOB

#define STUP1 GPIO_PIN_9
#define STUP2 GPIO_PIN_8
#define STUP5 GPIO_PIN_15
#define STUP6 GPIO_PIN_14
#define STUP3 GPIO_PIN_13
#define STUP4 GPIO_PIN_12
#define STUP7 GPIO_PIN_11
#define STUP8 GPIO_PIN_10
#endif

#define IN1_Pin GPIO_PIN_3
#define IN1_GPIO_Port GPIOA
#define IN2_Pin GPIO_PIN_4
#define IN2_GPIO_Port GPIOA
#define IN3_Pin GPIO_PIN_5
#define IN3_GPIO_Port GPIOA
#define IN4_Pin GPIO_PIN_6
#define IN4_GPIO_Port GPIOA
#define IN5_Pin GPIO_PIN_7
#define IN5_GPIO_Port GPIOA
#define IN6_Pin GPIO_PIN_0
#define IN6_GPIO_Port GPIOB
#define IN7_Pin GPIO_PIN_1
#define IN7_GPIO_Port GPIOB
#define IN8_Pin GPIO_PIN_2
#define IN8_GPIO_Port GPIOB

extern uint8_t one[16][8];
extern uint8_t two[16][8];
extern uint8_t three[16][8];
extern uint8_t four[16][8];
extern uint8_t five[16][8];
extern uint8_t six[16][8];
extern uint8_t seven[16][8];
extern uint8_t eight[16][8];
extern uint8_t nine[16][8];
extern uint8_t zero[16][8];
extern uint8_t up[16][8];
extern uint8_t down[16][8];
extern uint8_t equal[16][8];
extern uint8_t characterP[16][8];
extern uint8_t characterR[16][8];
extern uint8_t characterO[16][8];
extern uint8_t blank[16][8];
extern uint8_t arrowUp1[16][8];
extern uint8_t arrowUp2[16][8];
extern uint8_t arrowUp3[16][8];
extern uint8_t arrowUp4[16][8];
extern uint8_t arrowDown1[16][8];
extern uint8_t arrowDown2[16][8];
extern uint8_t arrowDown3[16][8];
extern uint8_t arrowDown4[16][8];

extern uint8_t one_1[16][8];
extern uint8_t one_2[16][8];
extern uint8_t two_1[16][8];
extern uint8_t two_2[16][8];
extern uint8_t three_1[16][8];
extern uint8_t three_2[16][8];
extern uint8_t four_1[16][8];
extern uint8_t four_2[16][8];
extern uint8_t five_1[16][8];
extern uint8_t five_2[16][8];
extern uint8_t six_1[16][8];
extern uint8_t six_2[16][8];
extern uint8_t seven_1[16][8];
extern uint8_t seven_2[16][8];
extern uint8_t eight_1[16][8];
extern uint8_t eight_2[16][8];
extern uint8_t nine_1[16][8];
extern uint8_t nine_2[16][8];
extern uint8_t arrowUp_1[16][8];
extern uint8_t arrowUp_2[16][8];
extern uint8_t arrowDown_1[16][8];
extern uint8_t arrowDown_2[16][8];

#ifdef __cplusplus
}
#endif

#endif
