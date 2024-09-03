#include "ServoLib.h"

#define MINIMUM_TIM 650
#define MAXIMUM_TIM 2700
#define MINIMUM_ANGLE 0.0f
#define MAXIMUM_ANGLE 180.0f

static uint16_t AngleToTim(float angle)
{
    uint16_t tim;

    if (angle <= MINIMUM_ANGLE)
    {
        tim = MINIMUM_TIM;
    }
    else if (angle >= MAXIMUM_ANGLE)
    {
        tim = MAXIMUM_TIM;
    }
    else
    {
        uint16_t range = MAXIMUM_TIM - MINIMUM_TIM;
        tim = (uint16_t)((angle / MAXIMUM_ANGLE) * range) + MINIMUM_TIM;
    }

    return tim;
}

void servoSetAngle (float angle ,TIM_HandleTypeDef *htim, uint32_t Channel)
{
	__HAL_TIM_SET_COMPARE(htim,Channel,AngleToTim(angle));
	HAL_Delay(1);
}

float ADC_TO_ANGLE (uint16_t value)
{
	float angle = value * MAXIMUM_ANGLE / 4095.0f;
	return angle;
}





