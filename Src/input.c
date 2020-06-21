#include "input.h"

uint8_t ReadBinaryInputs() {
	uint8_t in[5];
	uint8_t result = 0;

	in[0] = HAL_GPIO_ReadPin(IN1_GPIO_Port, IN1_Pin);
	in[1] = HAL_GPIO_ReadPin(IN2_GPIO_Port, IN2_Pin);
	in[2] = HAL_GPIO_ReadPin(IN3_GPIO_Port, IN3_Pin);
	in[3] = HAL_GPIO_ReadPin(IN4_GPIO_Port, IN4_Pin);
#ifdef MATRIX_BIG
	in[4] = HAL_GPIO_ReadPin(IN5_GPIO_Port, IN5_Pin);
#endif
#ifdef MATRIX_SMALL
	in[4] = HAL_GPIO_ReadPin(IN7_GPIO_Port, IN7_Pin);
#endif

	for (uint8_t i = 0; i < 5; i++) {
		result |= in[i] << i;
	}
	return result;
}

uint8_t ReadArrowInputs() {
	uint8_t in[2];
	uint8_t result = 0;

#ifdef MATRIX_BIG
	in[0] = HAL_GPIO_ReadPin(IN6_GPIO_Port, IN6_Pin);
	in[1] = HAL_GPIO_ReadPin(IN7_GPIO_Port, IN7_Pin);
#endif
#ifdef MATRIX_SMALL
	in[0] = HAL_GPIO_ReadPin(IN5_GPIO_Port, IN5_Pin);
	in[1] = HAL_GPIO_ReadPin(IN6_GPIO_Port, IN6_Pin);
#endif
	for (uint8_t i = 0; i <= 1; i++) {
		result |= in[i] << i;
	}
	return result;
}

void WriteBinaryData(uint8_t result, uint8_t arrow, uint8_t counter) {
	uint8_t buffer[16][8];

	switch (arrow) {
	case ARROW_UP:
		for (uint8_t i = 0; i <= 7; i++) {
			for (uint8_t j = 0; j <= 15; j++) {
				if (counter <= 10)
					buffer[j][i] = arrowUp4[j][i];
				if (counter > 10 && counter <= 20)
					buffer[j][i] = arrowUp3[j][i];
				if (counter > 20 && counter <= 30)
					buffer[j][i] = arrowUp2[j][i];
				if (counter > 30 && counter <= 40)
					buffer[j][i] = arrowUp1[j][i];
			}
		}
		break;
	case ARROW_DOWN:
		for (uint8_t i = 0; i <= 7; i++) {
			for (uint8_t j = 0; j <= 15; j++) {
				if (counter <= 10)
					buffer[j][i] = arrowDown4[j][i];
				if (counter > 10 && counter <= 20)
					buffer[j][i] = arrowDown3[j][i];
				if (counter > 20 && counter <= 30)
					buffer[j][i] = arrowDown2[j][i];
				if (counter > 30 && counter <= 40)
					buffer[j][i] = arrowDown1[j][i];
			}
		}
		break;
	default:
		for (uint8_t i = 0; i <= 7; i++) {
			for (uint8_t j = 0; j <= 15; j++) {
				buffer[j][i] = blank[j][i];
			}
		}
	}

	switch (result) {
	case LEVEL1:
		LCDWriteCharacter(characterP, characterO, buffer);
		break;
	case LEVEL2:
		LCDWriteCharacter(characterP, characterR, buffer);
		break;
	case LEVEL3:
		LCDWriteCharacter(blank, one, buffer);
		break;
	case LEVEL4:
		LCDWriteCharacter(blank, two, buffer);
		break;
	case LEVEL5:
		LCDWriteCharacter(blank, three, buffer);
		break;
	case LEVEL6:
		LCDWriteCharacter(blank, four, buffer);
		break;
	case LEVEL7:
		LCDWriteCharacter(blank, five, buffer);
		break;
	case LEVEL8:
		LCDWriteCharacter(blank, six, buffer);
		break;
	case LEVEL9:
		LCDWriteCharacter(blank, seven, buffer);
		break;
	case LEVEL10:
		LCDWriteCharacter(blank, eight, buffer);
		break;
	case LEVEL11:
		LCDWriteCharacter(blank, nine, buffer);
		break;
	case LEVEL12:
		LCDWriteCharacter(one, zero, buffer);
		break;
	case LEVEL13:
		LCDWriteCharacter(one, one, buffer);
		break;
	case LEVEL14:
		LCDWriteCharacter(one, two, buffer);
		break;
	case LEVEL15:
		LCDWriteCharacter(one, three, buffer);
		break;
	case LEVEL16:
		LCDWriteCharacter(one, four, buffer);
		break;
	case LEVEL17:
		LCDWriteCharacter(one, five, buffer);
		break;
	case LEVEL18:
		LCDWriteCharacter(one, six, buffer);
		break;
	case LEVEL19:
		LCDWriteCharacter(one, seven, buffer);
		break;
	case LEVEL20:
		LCDWriteCharacter(one, eight, buffer);
		break;
	case LEVEL21:
		LCDWriteCharacter(one, nine, buffer);
		break;
	case LEVEL22:
		LCDWriteCharacter(two, zero, buffer);
		break;
	case LEVEL23:
		LCDWriteCharacter(two, one, buffer);
		break;
	case LEVEL24:
		LCDWriteCharacter(two, two, buffer);
		break;
	case LEVEL25:
		LCDWriteCharacter(two, three, buffer);
		break;
	case LEVEL26:
		LCDWriteCharacter(two, four, buffer);
		break;
	case LEVEL27:
		LCDWriteCharacter(two, five, buffer);
		break;
	case LEVEL28:
		LCDWriteCharacter(two, six, buffer);
		break;
	case LEVEL29:
		LCDWriteCharacter(two, seven, buffer);
		break;
	case LEVEL30:
		LCDWriteCharacter(two, eight, buffer);
		break;
	case LEVEL31:
		LCDWriteCharacter(two, nine, buffer);
		break;
	default:
		LCDWriteCharacter(0, 0, 0);
	}
}

void WriteBinaryDataSmall(uint8_t result, uint8_t arrow, uint8_t counter) {
	uint8_t buffer1[16][8], buffer2[16][8];

	switch (arrow) {
	case ARROW_UP:
		for (uint8_t i = 0; i <= 7; i++) {
			for (uint8_t j = 0; j <= 15; j++) {
				buffer1[j][i] = arrowUp_1[j][i];
				buffer2[j][i] = arrowUp_2[j][i];
			}
		}
		break;
	case ARROW_DOWN:
		for (uint8_t i = 0; i <= 7; i++) {
			for (uint8_t j = 0; j <= 15; j++) {
				buffer1[j][i] = arrowDown_1[j][i];
				buffer2[j][i] = arrowDown_2[j][i];
			}
		}
	}

	if ((counter >= 0) && (counter <= 60) && (arrow != ARROW_NONE))	LCDWriteCharacter_small(buffer1, buffer2);
	else {
		switch (result) {
		case LEVEL1:
			LCDWriteCharacter_small(characterP, characterO);
			break;
		case LEVEL2:
			LCDWriteCharacter_small(characterP, characterR);
			break;
		case LEVEL3:
			LCDWriteCharacter_small(one_1, one_2);
			break;
		case LEVEL4:
			LCDWriteCharacter_small(two_1, two_2);
			break;
		case LEVEL5:
			LCDWriteCharacter_small(three_1, three_2);
			break;
		case LEVEL6:
			LCDWriteCharacter_small(four_1, four_2);
			break;
		case LEVEL7:
			LCDWriteCharacter_small(five_1, five_2);
			break;
		case LEVEL8:
			LCDWriteCharacter_small(six_1, six_2);
			break;
		case LEVEL9:
			LCDWriteCharacter_small(seven_1, seven_2);
			break;
		case LEVEL10:
			LCDWriteCharacter_small(eight_1, eight_2);
			break;
		case LEVEL11:
			LCDWriteCharacter_small(nine_1, nine_2);
			break;
		case LEVEL12:
			LCDWriteCharacter_small(one, zero);
			break;
		case LEVEL13:
			LCDWriteCharacter_small(one, one);
			break;
		case LEVEL14:
			LCDWriteCharacter_small(one, two);
			break;
		case LEVEL15:
			LCDWriteCharacter_small(one, three);
			break;
		case LEVEL16:
			LCDWriteCharacter_small(one, four);
			break;
		case LEVEL17:
			LCDWriteCharacter_small(one, five);
			break;
		case LEVEL18:
			LCDWriteCharacter_small(one, six);
			break;
		case LEVEL19:
			LCDWriteCharacter_small(one, seven);
			break;
		case LEVEL20:
			LCDWriteCharacter_small(one, eight);
			break;
		case LEVEL21:
			LCDWriteCharacter_small(one, nine);
			break;
		case LEVEL22:
			LCDWriteCharacter_small(two, zero);
			break;
		case LEVEL23:
			LCDWriteCharacter_small(two, one);
			break;
		case LEVEL24:
			LCDWriteCharacter_small(two, two);
			break;
		case LEVEL25:
			LCDWriteCharacter_small(two, three);
			break;
		case LEVEL26:
			LCDWriteCharacter_small(two, four);
			break;
		case LEVEL27:
			LCDWriteCharacter_small(two, five);
			break;
		case LEVEL28:
			LCDWriteCharacter_small(two, six);
			break;
		case LEVEL29:
			LCDWriteCharacter_small(two, seven);
			break;
		case LEVEL30:
			LCDWriteCharacter_small(two, eight);
			break;
		case LEVEL31:
			LCDWriteCharacter_small(two, nine);
			break;
		default:
			LCDWriteCharacter_small(0, 0);
		}
	}
}
