#ifndef GaussGun_H_
#define GaussGun_H_


/* 需要说明的是 单片机控制电炮 是低电平接通大功率开关 高电平关闭大功率开关 因此在不用的时候注意单片机引脚拉高 */
/* 否则 会损坏DCDC */
/* 同时系统上电的时候应该保证单片机和12V电源先上电 然后再接通DCDC升压电路 否则同样会损坏DCDC */

#include "main.h"


void GaussGun_Fire(uint16_t FireTime_us);

#endif
