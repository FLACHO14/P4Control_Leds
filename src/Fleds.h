#ifndef __FLEDS_H
#define __FLEDS_H

#include <stdint.h>
#include "hal.h"

extern int16_t nLeds;
void init_leds();
void update_leds();

gpioMap_t *myLeds();
gpioMap_t *myLeds2();
bool Led_ON(int16_t Led);
void led_OFF();
void initLeds();

#endif
