/*
 * interrupt.h
 *
 *  Created on: Mar 16, 2022
 *      Author: Ha Thien Quang
 */

#ifndef INC_INTERRUPT_H_
#define INC_INTERRUPT_H_

#include "allHeader.h"

#ifdef _INTERRPUT_C



extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;
/**
 * @brief interrput get data every have event
 * 
 * @param huart 
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

/**
 * @brief Interrput 0.1s read lenght and quantity data
 * 
 * @param htim poiter to timer
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif
#endif /* INC_INTERRUPT_H_ */
