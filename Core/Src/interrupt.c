/*
 * interrupt.c
 *
 *  Created on: Mar 16, 2022
 *      Author: Ha Thien Quang
 */

#define _INTERRPUT_C

#include "interrupt.h"



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
 if(huart->Instance == huart1.Instance)
 {
    readUart();
 }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
 {
	if (htim->Instance == htim2.Instance) {
		getLenghtAndQty();
	}
	if (htim->Instance == htim4.Instance) {
		getRealPulseEncoder = getRealPulsePosition();
		actualMet = convertRotationToMet(countTimeRotation, getRealPulseEncoder);
		speedEncoderRPM = getSpeedRPM(getRealPulseEncoder);
		//outputState(outData);
		outputState(outputData);
	}
}
