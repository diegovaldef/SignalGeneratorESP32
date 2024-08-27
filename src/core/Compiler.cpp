#include <Compiler.h>

ReadBuffer readBuffer;
WriteBuffer writeBuffer;
UBaseType_t spacesAvailable;

SemaphoreHandle_t xMutex;

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
  if (xSemaphoreTake(xMutex, 0) == pdTRUE) {
    openFile(STR_Root);
    xSemaphoreGive(xMutex);
  }

  int bytesRead = SD_ActualFile.readBytesUntil('\n', readBuffer.ACTUAL_BUF, READ_BUF_SIZE - 1);
  readBuffer.ACTUAL_BUF[bytesRead] = '\0';

  while (SD_ActualFile.available())
  {

    spacesAvailable = uxQueueSpacesAvailable(writeBuffer.TIME);

    if (spacesAvailable > 0)
    {

      bytesRead = SD_ActualFile.readBytesUntil('\n', readBuffer.NEXT_BUF, READ_BUF_SIZE - 1);
      readBuffer.NEXT_BUF[bytesRead] = '\0';

      double nextPeriod;
      sscanf(readBuffer.NEXT_BUF, "%lf", &nextPeriod);
      processSignal(readBuffer.ACTUAL_BUF, nextPeriod);

      strcpy(readBuffer.ACTUAL_BUF, readBuffer.NEXT_BUF);
    }

  }

  SD_ActualFile.close();

}

void fillBuffers()
{

  if (xSemaphoreTake(xMutex, 0) == pdTRUE) {
    openFile(STR_Root);
    xSemaphoreGive(xMutex);
  }

  int bytesRead = SD_ActualFile.readBytesUntil('\n', readBuffer.ACTUAL_BUF, READ_BUF_SIZE - 1);
  readBuffer.ACTUAL_BUF[bytesRead] = '\0';

  while (SD_ActualFile.available())
  {
    bytesRead = SD_ActualFile.readBytesUntil('\n', readBuffer.NEXT_BUF, READ_BUF_SIZE - 1);
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

  SD_ActualFile.close();

}

void init_Signal(){

  Serial.println("Calculando valores mínimos y máximos...");
  readMinMax();

  Serial.println("Creando Buffers de datos...");
  fillBuffers();

  Serial.println("Proceso Completado");

}