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

void readUart(void)
{
    lastReceviceTime = HAL_GetTick() + KeyTimeout;
    bufferData[countRxByte] = rxData;
    countRxByte++;
    totalCountbyte++;
    HAL_UART_Receive_IT(&PORD, &rxData, 1);
}

void getLenghtAndQty(void)
{
  if(HAL_GetTick() > lastReceviceTime)
  {
    lastReceviceTime = UINT_MAX;
    rxData = 0;
    countRxByte = 0;
    for(int i = 0; i < 10; i++)
    {
      qtyCutData[i] = 0;
      if(bufferData[i] == 32)
      {
        for(int j = 0; j < i; j++)
        {
          qtyCutData[j] = bufferData[j];
        }
        for(int j = i + 1; j < 10; j++)
        {
          leghtCutData[j - i - 1] = bufferData[j];
        }
      }
    }
    for(int i = 0; i < 10; i++)
    {
      bufferData[i] = 0;
    }
  }
  leghtRequest = (atof((char*) (leghtCutData))) * 100;
  quantityRequest = (atoi((char*) qtyCutData));
}


