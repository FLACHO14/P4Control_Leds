#include <Arduino.h>
#include <stdint.h>
#include <stdbool.h>



extern "C"{
  #include "hal.h"
  #include "Fleds.h"
  #include "pulsantes.h"
}

int16_t interval = 1000;    // Intervalo de tiempo en milisegundos
unsigned long prevMillis = 0;  // Almacena el tiempo en milisegundos
int16_t mov = 0;


void setup() {
  Serial.begin(115200);

  initLeds();

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);

  prevMillis = millis();  // Inicializa el tiempo previo
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - prevMillis >= interval) {
    prevMillis = currentMillis;  // Actualiza el tiempo previo

    gpioMap_t *l = myLeds();

    led_OFF();  // Apaga todos los LEDs
    Led_ON(l[mov]);  // Enciende el LED actual

    mov++;  // Incrementa el índice
    if (mov >= nLeds - 1) {
      mov = 0;  // Resetea el índice si ha pasado por todos los LEDs
    }
  }

  // Leer los botones
  int n[3];
  n[0] = leerBot(SW1);
  n[1] = leerBot(SW2);
  n[2] = leerBot(SW3);
  
  char buffer[50];
  sprintf(buffer, "%d %d %d \n", n[0], n[1], n[2]);
  Serial.print(buffer);
}

