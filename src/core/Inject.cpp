#include <Inject.h>

Adafruit_MCP4728 mcp;
TaskHandle_t TaskInjectHandle;


void MCPBegin(){

  if(!mcp.begin()){
    Serial.println("Failed to find MCP4728 chip");
    //while (1) {
    //  vTaskDelay(1);
    //}
  }

}

void createTaskInject(){

  MCPBegin();
  xTaskCreatePinnedToCore(
      TaskInject,
      "TaskInject",
      1024 * 10,
      NULL,
      16,
      &TaskInjectHandle,
      0);

}

void TaskInject(void *pvParameters)
{

  initTimer();
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
      xQueueReceive(writeBuffer.TIME, &deltaTime, portMAX_DELAY);

      //mcp.fastWrite(ch1, ch2, ch3, ch4);
      mcp.setChannelValue(MCP4728_CHANNEL_A, ch1, MCP4728_VREF_VDD);
      mcp.setChannelValue(MCP4728_CHANNEL_B, ch2, MCP4728_VREF_VDD);
      mcp.setChannelValue(MCP4728_CHANNEL_C, ch3, MCP4728_VREF_VDD);
      mcp.setChannelValue(MCP4728_CHANNEL_D, ch4, MCP4728_VREF_VDD);
      vMicrosecondsdelay(deltaTime);
    }
  }
}
