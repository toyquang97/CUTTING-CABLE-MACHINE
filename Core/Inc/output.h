/*
 * output.h
 *
 *  Created on: Mar 16, 2022
 *      Author: Ha Thien Quang
 */

#ifndef INC_OUTPUT_H_
#define INC_OUTPUT_H_

#define SCK (*(volatile uint32_t *)0x42210194)
#define PIN_A6 (*(volatile uint32_t *)0x42210118) // i
#define PIN_A7 (*(volatile uint32_t *)0x4221019C)
#define HC959_SEl (*(volatile uint32_t *)0x42210184) // PA1_O
#define HC166_SEl (*(volatile uint32_t *)0x422101BC) // PA15_O

#define HC166_PARA_EN() HC166_SEl = 0 // HAL_GPIO_WritePin(HC166_SEL_GPIO_Port, HC166_SEL_Pin, GPIO_PIN_RESET) //LATAbits.LATA5 = 0
#define HC166_SERI_EN() HC166_SEl = 1 // HAL_GPIO_WritePin(HC166_SEL_GPIO_Port, HC166_SEL_Pin, GPIO_PIN_SET)   //LATAbits.LATA5 = 1
#define HC166_CLK_HIGH() SCK = 1      // HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_SET)         //LATCbits.LATC3 = 1
#define HC166_CLK_LOW() SCK = 0       // HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_RESET)       //LATCbits.LATC3 = 0
#define HC595_LUCK_EN() HC959_SEl = 1 // HAL_GPIO_WritePin(HC595_SEL_GPIO_Port, HC595_SEL_Pin, GPIO_PIN_SET) //      //LATAbits.LATA4 = 1
#define HC595_LUCK_DIS() HC959_SEl = 0
#define bit_select(B, i) ((B >> i) & 1)  // check if bit is set
#define bit_set(B, i) (B |= (1 << i))    // set bit
#define bit_reset(B, i) (B &= ~(1 << i)) // reset bit

#define __EN_XBC    bit_set(outputData, 15)
#define __EN_XBO    bit_set(outputData, 14)
#define __EN_XB1    bit_set(outputData, 13)
#define __EN_XB2    bit_set(outputData, 12)
#define __EN_XB3    bit_set(outputData, 11)
#define __EN_XB4    bit_set(outputData, 10)
#define __EN_XB5    bit_set(outputData, 9)
#define __EN_XB6    bit_set(outputData, 8)

#define __EN_XB7    bit_set(outputData, 23)
#define __EN_XB8    bit_set(outputData, 22)
#define __EN_XB9    bit_set(outputData, 21)
#define __EN_XB10   bit_set(outputData, 20)
#define __EN_XB11   bit_set(outputData, 19)
#define __EN_XB12   bit_set(outputData, 18)
#define __EN_XB13   bit_set(outputData, 17)
#define __EN_XFM    bit_set(outputData, 16)


#define __EN_XUP    bit_set(outputData, 7)
#define __EN_XBP    bit_set(outputData, 6)
#define __EN_XDN    bit_set(outputData, 5)
#define __EN_XFAN   bit_set(outputData, 4)
#define __EN_XATT   bit_set(outputData, 3)
#define __EN_XLIGHT bit_set(outputData, 2)
#define __EN_XB21   bit_set(outputData, 1)
#define __EN_XB22   bit_set(outputData, 0)



#define __DIS_XBC    bit_reset(outputData, 15)
#define __DIS_XBO    bit_reset(outputData, 14)
#define __DIS_XB1    bit_reset(outputData, 13)
#define __DIS_XB2    bit_reset(outputData, 12)
#define __DIS_XB3    bit_reset(outputData, 11)
#define __DIS_XB4    bit_reset(outputData, 10)
#define __DIS_XB5    bit_reset(outputData, 9)
#define __DIS_XB6    bit_reset(outputData, 8)

#define __DIS_XB7    bit_reset(outputData, 23)
#define __DIS_XB8    bit_reset(outputData, 22)
#define __DIS_XB9    bit_reset(outputData, 21)
#define __DIS_XB10   bit_reset(outputData, 20)
#define __DIS_XB11   bit_reset(outputData, 19)
#define __DIS_XB12   bit_reset(outputData, 18)
#define __DIS_XB13   bit_reset(outputData, 17)
#define __DIS_XFM    bit_reset(outputData, 16)


#define __DIS_XUP    bit_reset(outputData, 7)
#define __DIS_XBP    bit_reset(outputData, 6)
#define __DIS_XDN    bit_reset(outputData, 5)
#define __DIS_XFAN   bit_reset(outputData, 4)
#define __DIS_XATT   bit_reset(outputData, 3)
#define __DIS_XLIGHT bit_reset(outputData, 2)
#define __DIS_XB21   bit_reset(outputData, 1)
#define __DIS_XB22   bit_reset(outputData, 0)

#ifdef _OUTPUT_C

#include "allHeader.h"

uint32_t volatile outputData = 0;
uint8_t outData[3];
/**
 * @brief
 *
 */
void changeStateRelay(void);

/**
 * @brief
 *
 */
// void outputState(uint8_t *pData);
void outputState(uint32_t pData);

/**
 * @brief
 *
 */
void changeStateLed(void);

/**
 * @brief
 *
 */
uint8_t SPI_SendOneByte(uint8_t dat);

/**
 * @brief 
 * 
 */
void initOutput(void);

#else

extern uint32_t volatile outputData;
extern uint8_t outData[3];
// extern void     outputState(uint8_t *pData);
extern void initOutput(void);
extern void outputState(uint32_t pData);
extern uint8_t SPI_SendOneByte(uint8_t dat);

#endif
#endif /* INC_OUTPUT_H_ */
