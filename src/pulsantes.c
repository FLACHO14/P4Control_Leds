#include <Arduino.h>
#include <stdint.h>
#include "pulsantes.h"

bool leerBot(int16_t bot) {
  return digitalRead(bot) == LOW; // LOW indica que el botón está presionado
}


///////////// add sistema anti rebote ///////////////


void initButton(DebounceButton *button, int16_t pin, uint32_t debounceDelay) {
    button->state = BUTTON_UP;
    button->pin = pin;
    button->lastDebounceTime = 0;
    button->debounceDelay = debounceDelay;
}

void updateButton(DebounceButton *button) {
    bool buttonPressed = leerBot(button->pin);
    uint32_t currentTime = millis();

    switch (button->state) {
        case BUTTON_UP:
            if (buttonPressed) {
                button->state = BUTTON_FALLING;
                button->lastDebounceTime = currentTime;
            }
            break;

        case BUTTON_FALLING:
            if (currentTime - button->lastDebounceTime > button->debounceDelay) {
                if (buttonPressed) {
                    button->state = BUTTON_DOWN;
                    buttonPressedEvent();
                } else {
                    button->state = BUTTON_UP;
                }
            }
            break;

        case BUTTON_DOWN:
            if (!buttonPressed) {
                button->state = BUTTON_RISING;
                button->lastDebounceTime = currentTime;
            }
            break;

        case BUTTON_RISING:
            if (currentTime - button->lastDebounceTime > button->debounceDelay) {
                if (!buttonPressed) {
                    button->state = BUTTON_UP;
                    buttonReleasedEvent();
                } else {
                    button->state = BUTTON_DOWN;
                }
            }
            break;
    }
}

void buttonPressedEvent() {
    // Implementar la lógica cuando el botón es presionado
    Serial.println("Button Pressed!");
}

void buttonReleasedEvent() {
    // Implementar la lógica cuando el botón es liberado
    Serial.println("Button Released!");
}
