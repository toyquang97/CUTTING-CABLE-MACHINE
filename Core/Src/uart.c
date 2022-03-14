/**
 * @file uart.c
 * @author GAREN
 * @brief 
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define _UART_C


#include "uart.h"


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
 if(huart->Instance == huart1.Instance)
 {
    readUart();
 }
}

void readUart(void)
{
  HAL_UART_Receive_IT(&PORD,rxData,1);
}


float stringToFloat(uint8_t *pData)
{
  float number = 0;
  uint32_t buffer;
  for (uint8_t i = 0; i < 3; i++)
  {
    buffer = (pData + i) << (3-i);
  }
  
  return number;
}
