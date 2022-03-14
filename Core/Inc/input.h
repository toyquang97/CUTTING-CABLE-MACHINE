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

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief read status of input digital
 * 
 * @param pinRead 
 * @return uint8_t :0 : no signal
 *                  1 : Push
 *                  2 : Press
 */
uint8_t readStatusButton(uint8_t pinRead); 

/**
 * @brief read input encoder
 * 
 * @return uint32_t pulse of encoder
 */
uint32_t readEncoder(void);



#endif _INPUT_H