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

#ifdef _INPUT_C

int16_t     getRealPulseEncoder = 0;
int16_t     getPosition         = 0;
uint32_t    realPulse           = 0;
uint8_t     countTimeRotation   = 0;
int16_t     positionDirective   = 0;
int16_t     speedEncoderRPM     = 0;
float       actualMet           = 0;
int16_t     oldPositionEncoder  = 0;
int16_t     countIndex          = 0;

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

#else
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
#endif
#endif
