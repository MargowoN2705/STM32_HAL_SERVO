#pragma once
#include "stm32l4xx.h"

void servoSetAngle (float angle ,TIM_HandleTypeDef *htim, uint32_t Channel);

float ADC_TO_ANGLE (uint16_t value);



