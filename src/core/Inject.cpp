#include <Inject.h>

Adafruit_MCP4728 mcp;
TaskHandle_t TaskInjectHandle;

uint16_t ch1;
uint16_t ch2;
uint16_t ch3;
uint16_t ch4;
uint64_t microseconds;

void MCPBegin(){

  if(!mcp.begin()){
    Serial.println("Failed to find MCP4728 chip");
    while (1) {
     vTaskDelay(1);
    }
  }

}

void createTaskInject(){

  MCPBegin();
  xTaskCreatePinnedToCore(
      TaskInject,
      "TaskInject",
      1024 * 10,
      NULL,
      2,
      &TaskInjectHandle,
      0);

}

void TaskInject(void *pvParameters)
{

  init_timer();
  vTaskSuspend(TaskInjectHandle);

  while (true)
  {
  
    spacesAvailable = uxQueueSpacesAvailable(writeBuffer.TIME);

    if (spacesAvailable < WRITE_BUF_SIZE)
    {

      xQueueReceive(writeBuffer.CH1, &ch1 , portMAX_DELAY);
      xQueueReceive(writeBuffer.CH2, &ch2 , portMAX_DELAY);
      xQueueReceive(writeBuffer.CH3, &ch3 , portMAX_DELAY);
      xQueueReceive(writeBuffer.CH4, &ch4 , portMAX_DELAY);
      xQueueReceive(writeBuffer.TIME, &microseconds, portMAX_DELAY);

      mcp.fastWrite(ch1, ch2, ch3, ch4);
      
      vMicrosecondsdelay(microseconds);

    }
  }
}
