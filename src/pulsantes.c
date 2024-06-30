#include "pulsantes.h"

bool leerBot(int16_t bot) {
    return digitalRead(bot) == LOW;
}

void initButton(DebounceButton *button, int16_t pin, uint32_t debounceDelay) {
    button->pin = pin;
    button->state = LOW;
    button->lastState = LOW;
    button->lastDebounceTime = 0;
    button->debounceDelay = debounceDelay;
    pinMode(pin, INPUT);
}

void updateButton(DebounceButton *button) {
    int reading = digitalRead(button->pin);
    if (reading != button->lastState) {
        button->lastDebounceTime = millis();
    }

    if ((millis() - button->lastDebounceTime) > button->debounceDelay) {
        if (reading != button->state) {
            button->state = reading;
            if (button->state == LOW && button->lastState == HIGH) {
                buttonPressedEvent(button->pin);
            }
        }
    }
    button->lastState = reading;
}
