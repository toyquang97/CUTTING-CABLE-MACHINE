/**
 * @file input.h
 * @author Garen
 * @brief 
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _INPUT_H
#define _INPUT_H
#include <allHeader.h>

// SCALEROTATION WILL BE CHANGE FOR REALITY
#define  SCALEROTATION 10

#define SCK (*(volatile uint32_t *)0x42210194)

#define PIN_A2 (*(volatile uint32_t *)0x42210188)  //i

#define PIN_A4 (*(volatile uint32_t *)0x42210190)  //i

#define PIN_A6 (*(volatile uint32_t *)0x42210118)  //i
#define PIN_A7 (*(volatile uint32_t *)0x4221019C)  //out

#define HC959_SEl (*(volatile uint32_t *)0x42210184)  //PA1_O
#define HC166_SEl (*(volatile uint32_t *)0x422101BC)  //PA15_O
#define USART2_TX_HIGH PIN_A2 = 1
#define USART2_TX_LOW PIN_A2 = 0
#define USART2_CLK_HIGH PIN_A4 = 1
#define USART2_CLK_LOW PIN_A4 = 0

#define	MAX_IN					70		//24�����밴ť
#define	MAX_OUT				70		//24����ť���2����վ�����
#define	MAX_IN_BYTE		(MAX_IN/8+1)
#define	MAX_FLOOR			60		

#define	HC166_PARA_EN()			HC166_SEl =0	//HAL_GPIO_WritePin(HC166_SEL_GPIO_Port, HC166_SEL_Pin, GPIO_PIN_RESET)	//LATAbits.LATA5 = 0
#define	HC166_SERI_EN()			HC166_SEl =1	//HAL_GPIO_WritePin(HC166_SEL_GPIO_Port, HC166_SEL_Pin, GPIO_PIN_SET)		//LATAbits.LATA5 = 1
#define	HC166_CLK_HIGH()		SCK = 1			//HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_SET)					//LATCbits.LATC3 = 1
#define	HC166_CLK_LOW()			SCK = 0			//HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_RESET)				//LATCbits.LATC3 = 0
#define	HC595_LUCK_EN()			HC959_SEl =1	//HAL_GPIO_WritePin(HC595_SEL_GPIO_Port, HC595_SEL_Pin, GPIO_PIN_SET)	//			//LATAbits.LATA4 = 1
#define	HC595_LUCK_DIS()		HC959_SEl =0	//HAL_GPIO_WritePin(HC595_SEL_GPIO_Port, HC595_SEL_Pin, GPIO_PIN_RESET)	//LATAbits.LATA4 = 0

#ifdef _INPUT_C
uint8_t mExtern_Number = 1;
int16_t     getRealPulseEncoder = 0;
int16_t     getPosition         = 0;
uint32_t    realPulse           = 0;
uint8_t     countTimeRotation   = 0;
int16_t     positionDirective   = 0;
int16_t     speedEncoderRPM     = 0;
float       actualMet           = 0;
int16_t     oldPositionEncoder  = 0;
int16_t     countIndex          = 0;
uint8_t	volatile	input [3][MAX_IN_BYTE];						/* input variables for debouncing		*/
uint8_t 	volatile	in[MAX_IN_BYTE];								/* variable for input after debouncing	*/
uint8_t						inold[MAX_IN_BYTE];							/* variable to save old input state		*/
uint8_t 	volatile	out[MAX_IN_BYTE] = {0};							/* output state							*/
uint8_t						in_polarity[MAX_IN_BYTE];					/* input is inverted / not inverted		*/
/**
 * @brief read status of input digital
 * 
 * @param pinRead 
 * @return uint8_t :0 : no signal
 *                  1 : Push
 *                  2 : Press
 */
uint8_t readStateButton(uint8_t pinRead); 

/**
 * @brief read input encoder
 * 
 * @return uint32_t pulse of encoder
 */
int32_t readEncoder(void);


/** @brief convert to MET
 *
 */
float convertRotationToMet(uint8_t counterRotation,int16_t pulseEncoder);

/** @brief get how many time encoder was rotate
 *
 */
uint8_t getCountTimeRotation(int16_t pulseEncoder);

/** @brief measure speed of encoder by RPM
 *
 */

int16_t getSpeedRPM(int16_t positionEncoder);


void ReadInput(void);


#else
extern uint8_t mExtern_Number ;
extern int16_t oldPositionEncoder;
extern int16_t countIndex;
extern int16_t getRealPulseEncoder;
extern int16_t getPosition;
extern int16_t positionDirective;
extern int16_t speedEncoderRPM;
extern int32_t realPulse;
extern uint8_t ratioScale;
extern uint8_t countTimeRotation;
extern float   actualMet;
extern int32_t readEncoder(void);
extern int16_t getRealPulsePosition(void);
extern uint8_t getCountTimeRotation(int16_t pulseEncoder);
extern float   convertRotationToMet(uint8_t counterRotation,int16_t pulseEncoder);
extern int16_t getSpeedRPM(int16_t positionEncoder);
extern void ReadInput(void);

extern	uint8_t	volatile	input[3][MAX_IN_BYTE];						/* input variables for debouncing		*/
extern	uint8_t 	volatile	in[MAX_IN_BYTE];								/* variable for input after debouncing	*/
extern	uint8_t						inold[MAX_IN_BYTE];							/* variable to save old input state		*/
#endif
#endif
