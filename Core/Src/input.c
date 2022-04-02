/*
 * input.c
 *
 *  Created on: Mar 25, 2022
 *      Author: HT-QUANG
 */

#define _INPUT_C

#include "input.h"

int32_t readEncoder(void)
{
	static int32_t countValue = 0;
	countValue = (int32_t)TIM3->CNT;
	if (TIM3->CNT > 65535 - 10 || TIM3->CNT > 3999)
	{
		TIM3->CNT = 0;
	}
	return countValue;
}

int16_t getRealPulsePosition(void)
{
	realPulse = readEncoder();
	positionDirective = (int32_t)realPulse;
	getPosition = positionDirective / 4;
	if (getPosition > 999)
	{
		TIM3->CNT = 0;
		countTimeRotation++;
	}
	return getPosition;
}

float convertRotationToMet(uint16_t counterRotation, int16_t pulseEncoder)
{
	float actualPosition = 0;
	actualPosition = (counterRotation + (float)(pulseEncoder / 1000)) / SCALEROTATION;
	return actualPosition;
}

int16_t getSpeedRPM(int16_t positionEncoder)
{
	static int16_t speedEncoder = 0;
	countIndex++;
	if(countIndex == 100)
	{
		if(positionEncoder > oldPositionEncoder)
		{
			speedEncoder = ((positionEncoder - oldPositionEncoder) * 10 * 60 )/1000;
		}
		if(positionEncoder == oldPositionEncoder)
		{
			speedEncoder = 0;
		}
		oldPositionEncoder = positionEncoder;
		countIndex = 0;
	}
	return speedEncoder;
}
