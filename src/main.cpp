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
  static int n[4] = {1, 0, 0, 0}; // Inicializa el vector n a cero
  unsigned long currentMillis = millis();

    // Actualiza el estado de n[0] y n[1] según los botones
  if (leerBot(SW1)) {
    n[0] = 0; // Si SW1 está presionado, n[0] se mantiene en 1
  }
  if (leerBot(SW2)) {
    n[0] = 1; // Si SW2 está presionado, n[0] vuelve a 0
  }

  if (currentMillis - prevMillis >= interval) {
    prevMillis = currentMillis;  // Actualiza el tiempo previo

    gpioMap_t *l = myLeds();
    gpioMap_t *l2 = myLeds2();

    led_OFF();  // Apaga todos los LEDs


    if (n[0] == 1) {
      Led_ON(l[mov]);  // Enciende el LED actual en la secuencia alterna
    } else {
      Led_ON(l2[mov]);  // Enciende el LED actual en la secuencia normal
    }

    mov++;  // Incrementa el índice
    if (mov >= nLeds) {
      mov = 0;  // Resetea el índice si ha pasado por todos los LEDs
    }





  }

  // Leer los botones
  
  n[1] = leerBot(SW2);
  n[2] = leerBot(SW3);
  n[3] = leerBot(SW4);
  
  char buffer[50];
  sprintf(buffer, "%d %d %d \n", n[0], n[1], n[2]);
  Serial.print(buffer);
}

