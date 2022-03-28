/*
 * output.c
 *
 *  Created on: Mar 16, 2022
 *      Author: Ha Thien Quang
 */

#define _OUTPUT_C

#include "output.h"

// void outputState(uint8_t *pData)
// {
//   uint8_t temp;
//   for (int i = 3; i > 0; i--)
//   {
//     temp = 0;
//     for (int j = 0; j < 8; j++)
//     {
//       temp <<= 1;
//       if (pData[i - 1] & (1 << j))
//         temp |= 0x01;
//     }
//     SPI_SendOneByte(temp);
//   }
// }

void initOutput(void)
{
    for (int i = 0; i < 24; i++)
    {
        bit_reset(outputData,i);
    }
}

void outputState(uint32_t pData)
{
  uint8_t temp;
  for (int i = 3; i > 0; i--)
  {
    temp = 0;
    for (int j = 0; j < 8; j++)
    {
      temp <<= 1;
      if (bit_select(pData,23))
        temp |= 0x01;
      pData = pData << 1;
    }
    SPI_SendOneByte(temp);
  }
}

uint8_t SPI_SendOneByte(uint8_t dat)
{
  HC595_LUCK_EN();
  SCK = 0;
  __NOP();
  for (int i = 7; i >= 0; i--)
  {
    PIN_A7 = (dat >> i) & 0x01;
    __NOP();
    SCK = 1;
    __NOP();
    __NOP();
    SCK = 0;
    __NOP();
    __NOP();
    __NOP();
  }
  HC595_LUCK_DIS();
  return dat;
}
