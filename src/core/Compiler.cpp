#include <Compiler.h>

ReadBuffer readBuffer;
WriteBuffer writeBuffer;
UBaseType_t spacesAvailable;

TaskHandle_t TaskCompilerHandle;

uint16_t ch1;
uint16_t ch2;
uint16_t ch3;
uint16_t ch4;
uint64_t deltaTime;

bool filling = false;

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

    ch1 = mapDouble(CH1, minCH1, maxCH1, 0, 4095);
    ch2 = mapDouble(CH2, minCH2, maxCH2, 0, 4095);
    ch3 = mapDouble(CH3, minCH3, maxCH3, 0, 4095);
    ch4 = mapDouble(CH4, minCH4, maxCH4, 0, 4095);

    deltaTime = (nextPeriod - PERIOD) * 1e6;

    showChannels();

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
  filling = true;

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

  filling = false;
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

  lv_label_set_text(ui_Label5, fileNameStd[selected].c_str());
  _ui_screen_change(&ui_Main, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 1000, &ui_Main_screen_init);

}

void showChannels(){

  if(filling){
    return;
  }

  if(ch1 < 0 || ch1 > 4095){ch1 = 0;}
  if(ch2 < 0 || ch2 > 4095){ch2 = 0;}
  if(ch3 < 0 || ch3 > 4095){ch3 = 0;}
  if(ch4 < 0 || ch4 > 4095){ch4 = 0;}

  lv_obj_set_style_bg_opa(ui_Panel1, map(ch1, 0, 4095, 10, 200), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel2, map(ch2, 0, 4095, 10, 200), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel3, map(ch3, 0, 4095, 10, 200), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel4, map(ch4, 0, 4095, 10, 200), LV_PART_MAIN | LV_STATE_DEFAULT);
  
}