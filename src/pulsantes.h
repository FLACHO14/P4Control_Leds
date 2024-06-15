#ifndef __PULSANTES_H
#define __PULSANTES_H


#include <stdint.h>
#include "hal.h"
#include <stdbool.h>

///////// add del sistema anti rebote///////


typedef enum {
    BUTTON_UP,
    BUTTON_FALLING,
    BUTTON_DOWN,
    BUTTON_RISING
} ButtonState;

typedef struct {
    ButtonState state;
    int16_t pin;
    uint32_t lastDebounceTime;
    uint32_t debounceDelay;
} DebounceButton;

bool leerBot(int16_t bot);
void initButton(DebounceButton *button, int16_t pin, uint32_t debounceDelay);
void updateButton(DebounceButton *button)






#endif
