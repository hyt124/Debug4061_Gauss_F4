#ifndef KEYPAD_H
#define KEYPAD_H

#include "stdint.h"
#include "stm32f4xx_hal.h"

uint16_t Key_scan(void);
void KeyShow_LCD(void);

#endif