#include <Arduino.h>
#include <Core.h>

void setup()
{

  Serial.begin(115200);
  setCpuFrequencyMhz(240);

  pinMode(dac1Pin, OUTPUT);
  pinMode(dac2Pin, OUTPUT);

  createTaskInject();
  createTaskCompiler();
  createTaskSD();
  createTaskScreen();

  vTaskDelete(NULL);
}

void loop()
{
}
