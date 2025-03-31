#include <SdManager.h>

SPIClass vspi(VSPI);
TaskHandle_t TaskSDHandle;

File SD_Root;
String STR_Root;

bool noSDFound = false;
int delay_time = 0;

void createTaskSD()
{
  xTaskCreatePinnedToCore(
      TaskSD,
      "TaskSD",
      1024 * 10,
      NULL,
      10,
      &TaskSDHandle,
      1);

}

void TaskSD(void *pvParameters)
{
  vTaskSuspend(TaskSDHandle);

  while(true){

    _ui_screen_change(&ui_ErrorSD, LV_SCR_LOAD_ANIM_FADE_OUT, 0, delay_time, &ui_ErrorSD_screen_init);

    while(!SD.begin(SD_CS, vspi)){
      SD.begin(SD_CS, vspi);
      vTaskDelay(1);
    }

    while (!SD_Root)
    {
      SD_Root = SD.open(STR_Root, FILE_READ);
      vTaskDelay(1);
    }

    refreshRoller();
    _ui_screen_change(&ui_Explorador, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 0, &ui_Explorador_screen_init);
    noSDFound = false;

    globalStates.sd = false;
    reloadTasks();
  }

}

void openFileRead()
{
  SD_Root = SD.open(STR_Root, FILE_READ);
  if (!SD_Root)
  {
    delay_time = 0;
    noSDFound = true;
    globalStates.sd = true;
    reloadTasks();
  }
}

void openFileWrite()
{
  SD_Root = SD.open(STR_Root, FILE_WRITE);
  if (!SD_Root)
  {
    delay_time = 0;
    noSDFound = true;
    globalStates.sd = true;
    reloadTasks();
  }
}

void SDBegin()
{
  STR_Root = "/";

  if (!SD.begin(SD_CS, vspi))
  {
    delay_time = 3000;
    noSDFound = true;
    globalStates.sd = true;
    reloadTasks();
  }
  else
  {
    refreshRoller();
  }

}

