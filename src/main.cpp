#include <Arduino.h>
#include <Core.h>

void setup()
{

  Serial.begin(115200);
  setCpuFrequencyMhz(240);

  pinMode(dac1Pin, OUTPUT);
  pinMode(dac2Pin, OUTPUT);

  SDBegin();
  screenSetup();

  Serial.println("Calculando valores mínimos y máximos...");
  readMinMax();

  Serial.println("Creando Buffers de datos...");
  fillBuffers();

  Serial.println("Proceso Completado");

  Serial.print("Min CKP: ");
  Serial.println(minCH1, 6);
  Serial.print("Max CKP: ");
  Serial.println(maxCH1, 6);
  Serial.print("Min CMP1: ");
  Serial.println(minCH2, 6);
  Serial.print("Max CMP1: ");
  Serial.println(maxCH2, 6);
  Serial.print("Min CMP2: ");
  Serial.println(minCH3, 6);
  Serial.print("Max CMP2: ");
  Serial.println(maxCH3, 6);

  createTaskInject();
  

}

void loop()
{
  readSignal();
  lv_timer_handler(); /* let the GUI do its work */

}
