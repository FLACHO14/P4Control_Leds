#include <Arduino.h>
#include <stdint.h>
#include "Fleds.h"
#include "hal.h"

static const gpioMap_t leds[] = {Led_Vr, Led_Am, Led_Rj, Led_Az};
static const gpioMap_t leds2[] = {Led_Az, Led_Rj, Led_Am, Led_Vr};
int16_t nLeds = sizeof(leds) / sizeof(gpioMap_t);

gpioMap_t *myLeds(){
  return leds;
}
gpioMap_t *myLeds2(){
  return leds2;
}
bool Led_ON(int16_t Led) {
  switch (Led) {
    case Led_Vr:
    case Led_Am:
    case Led_Rj:
    case Led_Az:
      digitalWrite(Led, HIGH);
      break;
    default:
      return false;
  }
  return true;
}

void led_OFF() {
  for (int i = 0; i < nLeds; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void initLeds(){
  for (int i = 0; i < nLeds ; i++) {
    pinMode(leds[i], OUTPUT);
  } 
}

