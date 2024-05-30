#include <Arduino.h>
#include <stdint.h>
#include "pulsantes.h"

bool leerBot(int16_t bot) {
  return digitalRead(bot) == LOW; // LOW indica que el botón está presionado
}