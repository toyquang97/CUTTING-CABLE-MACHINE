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
        for(uint8_t k = 0; k < i; k++)
        {
          qtyCutData[k] = bufferData[k];
          if(k == i)
          {
            break;
          }
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
  if(totalCountbyte > 255)
  {
    totalCountbyte = 0;
  }
  leghtRequest = (atof((char*) (leghtCutData))) * 100;
  quantityRequest = (atoi((char*) qtyCutData));
}

void uartSendByte(uint8_t * pData, uint8_t len)
{
  HAL_UART_Transmit(&PORD, pData, len, 100);
}
