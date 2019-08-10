#ifndef LCD_MOD_H
#define LCD_MOD_H

#include "ILI93xx.h"

extern uint16_t lcd_flag;
extern uint16_t dis_flag;
extern uint16_t ang_flag;
extern uint16_t DoA;
extern uint16_t cnt;
extern uint16_t fire_flag;
extern uint8_t distance[];
extern uint32_t aim;
extern uint8_t angle[];
extern uint32_t aim_ang;

void mode_init(void);
void mode_display(void);
void mode1(void);
void mode2(void);
void mode3(void);
void mode4(void);
void mode5(void);

#endif