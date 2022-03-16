/**
 * @file motor.h
 * @author Garen
 * @brief 
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _MOTOR_H
#define _MOTOR_H

#include <allHeader.h>


typedef enum
{
    motorReady = 0,
    motorStart,
    motorRunning,
    motorStop
}MotorStatus_e;

typedef struct 
{
    MotorStatus_e motorStatus;
    uint32_t actualPosition;
}Motor_t;

/**
 * @brief 
 * 
 * @return uint8_t 
 */
Motor_t readStatusMotor(Motor_t *statusMotor);
  
/**
 * @brief 
 * 
 * @param readEncoder 
 * @return uint32_t 
 */
uint32_t readRealPosition(uint32_t readEncoder);

/**
 * @brief 
 * 
 * @param timeTransform 
 */
void transformDeltaToStar(uint8_t timeTransform);

/**
 * @brief 
 * 
 * @param timeTransform 
 */
void transformStarToDelta(uint8_t timeTransform);

/**
 * @brief 
 * 
 * @param positionStop 
 */
void stopMotor(uint32_t positionStop);

/**
 * @brief 
 * 
 */
void invertMotor(void);

/**
 * @brief 
 * 
 */
void returnHome(void);


#endif
