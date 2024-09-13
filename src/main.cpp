#include <Arduino.h>
#include <Core.h>

void setup()
{

  Serial.begin(115200);
  setCpuFrequencyMhz(240);

  pinMode(dac1Pin, OUTPUT);
  pinMode(dac2Pin, OUTPUT);

  pinMode(TFT_MOSI, OUTPUT);
  pinMode(TFT_MISO, INPUT);
  pinMode(TFT_SCLK, OUTPUT);
  pinMode(chipSelect, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
  pinMode(21, OUTPUT);

  createTaskInject();
  createTaskCompiler();
  createTaskSD();
  createTaskScreen();

  vTaskDelete(NULL);
}

void loop()
{
}
