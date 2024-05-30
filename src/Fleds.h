#ifndef __FLEDS_H
#define __FLEDS_H

#include <stdint.h>
#include "hal.h"

extern int16_t nLeds;

gpioMap_t *myLeds();
bool Led_ON(int16_t Led);
void led_OFF();
void initLeds();

#endif