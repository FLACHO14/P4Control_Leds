#ifndef PULSANTES_H
#define PULSANTES_H

#include <Arduino.h>

typedef struct {
    int pin;
    int state;
    int lastState;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;
} DebounceButton;

void init_pulsadores();
void update_pulsadores();
bool leerBot(int16_t bot);
void initButton(DebounceButton *button, int16_t pin, uint32_t debounceDelay);
void updateButton(DebounceButton *button);
void buttonPressedEvent();
void buttonReleasedEvent();

#endif
