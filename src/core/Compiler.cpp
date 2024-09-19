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
  double PERIOD, CH1, CH2, CH3, CH4;
  if (sscanf(line, "%lf %lf %lf %lf %lf", &PERIOD, &CH1, &CH2, &CH3, &CH4))
  {

    uint16_t ch1 = mapDouble(CH1, minCH1, maxCH1, 0, 4095);
    uint16_t ch2 = mapDouble(CH2, minCH2, maxCH2, 0, 4095);
    uint16_t ch3 = mapDouble(CH3, minCH3, maxCH3, 0, 4095);
    uint16_t ch4 = mapDouble(CH4, minCH4, maxCH4, 0, 4095);
    uint64_t deltaTime = (nextPeriod - PERIOD) * 1e6;

    xQueueSend(writeBuffer.CH1, &ch1, portMAX_DELAY);
    xQueueSend(writeBuffer.CH2, &ch2, portMAX_DELAY);
    xQueueSend(writeBuffer.CH3, &ch3, portMAX_DELAY);
    xQueueSend(writeBuffer.CH4, &ch4, portMAX_DELAY);
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

    if ((WRITE_BUF_SIZE - spacesAvailable) != WRITE_BUF_SIZE)
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
  spacesAvailable = uxQueueSpacesAvailable(writeBuffer.TIME);
  while ((WRITE_BUF_SIZE - spacesAvailable) != WRITE_BUF_SIZE)
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

      if ((WRITE_BUF_SIZE - spacesAvailable) != WRITE_BUF_SIZE)
      {
        processSignal(readBuffer.ACTUAL_BUF, nextPeriod);
      }
      else
      {
        break;
      }

      strcpy(readBuffer.ACTUAL_BUF, readBuffer.NEXT_BUF);
      vTaskDelay(1);
    }
    
    SD_Root.close();
  }
}

void init_Signal()
{

  Serial.println("Calculando valores mínimos y máximos...");
  readMinMax();

  Serial.println("Creando Buffers de datos...");
  fillBuffers();

  Serial.println("Proceso Completado");

  Serial.print("Min CH1: ");
  Serial.println(minCH1, 6);
  Serial.print("Max CH1: ");
  Serial.println(maxCH1, 6);
  Serial.print("Min CH2: ");
  Serial.println(minCH2, 6);
  Serial.print("Max CH2: ");
  Serial.println(maxCH2, 6);
  Serial.print("Min CH3: ");
  Serial.println(minCH3, 6);
  Serial.print("Max CH3: ");
  Serial.println(maxCH3, 6);
  Serial.print("Min CH4: ");
  Serial.println(minCH4, 6);
  Serial.print("Max CH4: ");
  Serial.println(maxCH4, 6);


  _ui_screen_change(&ui_Main, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 0, &ui_Main_screen_init);

}
