#include <Compiler.h>

ReadBuffer readBuffer;
WriteBuffer writeBuffer;
UBaseType_t spacesAvailable;

TaskHandle_t TaskCompilerHandle;

void createTaskCompiler()
{

  xTaskCreatePinnedToCore(
      TaskCompiler,
      "TaskCompiler",
      1024 * 10,
      NULL,
      2,
      &TaskCompilerHandle,
      0);

  vTaskSuspend(TaskCompilerHandle);
  

}

void TaskCompiler(void *pvParameters)
{
  
  init_Signal();
  vTaskSuspend(TaskCompilerHandle);

  while (true)
  {
    readSignal();
  }
}

void processSignal(const char *line, double nextPeriod)
{
  double PERIOD, CH1, CH2, CH3;
  if (sscanf(line, "%lf %lf %lf %lf", &PERIOD, &CH1, &CH2, &CH3))
  {

    uint16_t ch1 = mapDouble(CH1, minCH1, maxCH1, 0, 255);
    uint16_t ch2 = mapDouble(CH2, minCH2, maxCH2, 0, 255);
    uint16_t ch3 = mapDouble(CH3, minCH3, maxCH3, 0, 255);
    uint64_t deltaTime = (nextPeriod - PERIOD) * 1e6;

    xQueueSend(writeBuffer.CH1, &ch1, portMAX_DELAY);
    xQueueSend(writeBuffer.CH2, &ch2, portMAX_DELAY);
    xQueueSend(writeBuffer.CH3, &ch3, portMAX_DELAY);
    xQueueSend(writeBuffer.TIME, &deltaTime, portMAX_DELAY);
  }
}

void readSignal()
{
  openFile();

  int bytesRead = SD_Root.readBytesUntil('\n', readBuffer.ACTUAL_BUF, READ_BUF_SIZE - 1);
  readBuffer.ACTUAL_BUF[bytesRead] = '\0';

  while (SD_Root.available())
  {

    spacesAvailable = uxQueueSpacesAvailable(writeBuffer.TIME);

    if (spacesAvailable > 0)
    {

      bytesRead = SD_Root.readBytesUntil('\n', readBuffer.NEXT_BUF, READ_BUF_SIZE - 1);
      readBuffer.NEXT_BUF[bytesRead] = '\0';

      double nextPeriod;
      sscanf(readBuffer.NEXT_BUF, "%lf", &nextPeriod);
      processSignal(readBuffer.ACTUAL_BUF, nextPeriod);

      strcpy(readBuffer.ACTUAL_BUF, readBuffer.NEXT_BUF);
    }
    vTaskDelay(1);
  }

  SD_Root.close();
}

void fillBuffers()
{

  openFile();

  int bytesRead = SD_Root.readBytesUntil('\n', readBuffer.ACTUAL_BUF, READ_BUF_SIZE - 1);
  readBuffer.ACTUAL_BUF[bytesRead] = '\0';

  while (SD_Root.available())
  {
    bytesRead = SD_Root.readBytesUntil('\n', readBuffer.NEXT_BUF, READ_BUF_SIZE - 1);
    readBuffer.NEXT_BUF[bytesRead] = '\0';

    double nextPeriod;
    sscanf(readBuffer.NEXT_BUF, "%lf", &nextPeriod);

    spacesAvailable = uxQueueSpacesAvailable(writeBuffer.TIME);

    if (spacesAvailable > 0)
    {
      processSignal(readBuffer.ACTUAL_BUF, nextPeriod);
    }
    else
    {
      break;
    }

    strcpy(readBuffer.ACTUAL_BUF, readBuffer.NEXT_BUF);
  }

  SD_Root.close();
}

void init_Signal()
{

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

  _ui_screen_change(&ui_Main, LV_SCR_LOAD_ANIM_FADE_ON, 0 , 0, &ui_Main_screen_init);

}

