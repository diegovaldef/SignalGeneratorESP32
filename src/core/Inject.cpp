#include <Inject.h>

TaskHandle_t TaskInjectHandle;

uint16_t ch1;
uint16_t ch2;
uint16_t ch3;
uint64_t microseconds;

void createTaskInject(){

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
      xQueueReceive(writeBuffer.TIME, &microseconds, portMAX_DELAY);

      dacWrite(dac1Pin, ch1);
      dacWrite(dac2Pin, ch2);
      
      vMicrosecondsdelay(microseconds);

    }
  }
}
