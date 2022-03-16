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


#define KeyTimeout 1500

#ifdef _UART_C
#include "allHeader.h"
extern UART_HandleTypeDef huart1;
#define PORD huart1


uint8_t rxData;
uint8_t bufferData[10];
uint8_t leghtCutData[6];
uint8_t qtyCutData[3];
uint32_t totalCountbyte = 0;
uint32_t lastReceviceTime = UINT_MAX;
uint8_t countRxByte;
uint32_t leghtRequest = 0;
uint16_t quantityRequest = 0;


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
 * @brief get request lenght and quantity
 * 
 */
void getLenghtAndQty(void);

#else

extern uint8_t rxData;
extern uint8_t bufferData[10];
extern uint8_t leghtCutData[6];
extern uint8_t qtyCutData[3];
extern uint32_t lastReceviceTime;
extern uint32_t totalCountbyte;
extern uint8_t countRxByte;
extern uint32_t leghtRequest;
extern uint16_t quantityRequest;
extern void readUart(void);
extern void getLenghtAndQty(void);
extern void uartSendBuff(uint8_t * pData, uint8_t len);


#endif
#endif
