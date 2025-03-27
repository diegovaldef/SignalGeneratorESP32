#include <Arduino.h>
#include <Core.h>

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000);
  setCpuFrequencyMhz(240);
  WiFi.mode(WIFI_OFF);
  btStop();

  pinMode(SD_CS, OUTPUT);
  pinMode(TFT_CS, OUTPUT); 
  pinMode(TOUCH_CS, OUTPUT);

  pinMode(ledsPin, OUTPUT);
  pinMode(relePin, OUTPUT);

  vspi.begin(SCK_2, MISO_2, MOSI_2, SD_CS);

  createTaskInject();
  createTaskCompiler();
  createTaskSD();
  createTaskManager();
  createTaskScreen();
  createTaskScope();

  vTaskDelete(NULL);
}

void loop() 
{
  vTaskDelay(1);
}
