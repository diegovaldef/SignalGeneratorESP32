#include <Arduino.h>
#include <Core.h>

void setup()
{
  Serial.begin(115200);
  setCpuFrequencyMhz(240);

  pinMode(SD_CS, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
  pinMode(TOUCH_CS, OUTPUT);

  vspi.begin(SCK_2, MISO_2, MOSI_2, SD_CS);

  createTaskInject();
  createTaskCompiler();
  createTaskSD();
  createTaskScreen();
  createTaskScope();
  
  vTaskDelete(NULL);
}

void loop()
{
  delay(1000);
}
