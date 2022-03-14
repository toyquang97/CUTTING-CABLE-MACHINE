/**
 * @file uart.h
 * @author Garen 
 * @brief 
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef _UART_C
#define PORD huart1
uint8_t bufferData[8];
uint8_t rxData[8];
uint8_t txData[8];


/**
 * @brief 
 * 
 */
void readUart(void);

/**
 * @brief 
 * 
 * @param pData 
 * @param len 
 */
void uartSendBuff(uint8_t * pData, uint8_t len);

/**
 * @brief 
 * 
 * @param pData 
 * @return float 
 */
float stringToFloat(uint8_t *pData);

#else
extern uint8_t bufferData[];
extern uint8_t rxData[8];
extern uint8_t txData[8];

#endif 
#endif 