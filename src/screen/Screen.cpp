#include <Screen.h>

TaskHandle_t TaskScreenHandle;
bool signalRunning = false;
bool firstOpen = true;

const char _DIRECTORY_ = '0';
const char _FILE_ = '1';

void TaskScreen(void *pvParameters)
{
  while (true)
  {
    lv_timer_handler();
    vTaskDelay(5);
  }
}

void createTaskScreen()
{

  xTaskCreatePinnedToCore(
      TaskScreen,
      "TaskScreen",
      1024 * 10,
      NULL,
      1,
      &TaskScreenHandle,
      1);
}

void rollerUp(lv_event_t *e)
{

  if (lv_roller_get_selected(ui_Roller3) == 0)
  {
    lv_roller_set_selected(ui_Roller3, 2, LV_ANIM_ON);
  }
  else
  {

    uint32_t k = LV_KEY_UP;
    lv_event_send(ui_Roller3, LV_EVENT_KEY, &k);
  }
}

void rollerDown(lv_event_t *e)
{
  if (lv_roller_get_selected(ui_Roller3) == 2)
  {
    lv_roller_set_selected(ui_Roller3, 0, LV_ANIM_ON);
  }
  else
  {

    uint32_t k = LV_KEY_DOWN;
    lv_event_send(ui_Roller3, LV_EVENT_KEY, &k);
  }
}

void SignalStartStop(lv_event_t *e)
{
  if (signalRunning)
  {
    timerAlarmDisable(My_timer);
    timerStop(My_timer);
    vTaskSuspend(TaskCompilerHandle);
    vTaskSuspend(TaskInjectHandle);
    signalRunning = false;
  }
  else
  {
    timerAlarmEnable(My_timer);
    timerStart(My_timer);
    vTaskResume(TaskCompilerHandle);
    vTaskResume(TaskInjectHandle);
    signalRunning = true;
  }
}

void openTarget(lv_event_t *e)
{

  byte selected = lv_roller_get_selected(ui_Roller3);

  if (firstOpen)
  {
    STR_Root = fileName[selected];
    firstOpen = false;
  }
  else
  {
    STR_Root = STR_Root + fileName[selected];
  }

  if (fileType[selected] == _DIRECTORY_)
  {
    refreshRoller();
  }
  else
  {
    _ui_screen_change(&ui_Loading, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_Loading_screen_init);
    vTaskResume(TaskCompilerHandle);
  }
}

void backDirectory(lv_event_t *e)
{
  String lastFileName;
  int len = STR_Root.length();
  for (int i = len - 1; i >= 0; i--)
  {

    lastFileName = STR_Root[i] + lastFileName;

    if (STR_Root[i] == '/')
    {
      break;
    }
  }

  if (!(STR_Root.length() - lastFileName.length() == 0))
  {
    STR_Root.remove(STR_Root.length() - lastFileName.length(), lastFileName.length());
  }
  else
  {
    STR_Root = "/";
    firstOpen = true;
  }

  refreshRoller();
}

void resetSignal(lv_event_t * e)
{
  vTaskSuspend(TaskCompilerHandle);
  vTaskSuspend(TaskInjectHandle);
  
  timerAlarmDisable(My_timer);
  timerStop(My_timer);
  timerDetachInterrupt(My_timer);
  timerEnd(My_timer);
  signalRunning = false;
  
  minCH1 = 0;
  maxCH1 = 0;
  minCH2 = 0;
  maxCH2 = 0;
  minCH3 = 0;
  maxCH3 = 0;
  minCH4 = 0;
  maxCH4 = 0;

  uint64_t data;

  while (uxQueueMessagesWaiting(writeBuffer.CH1) > 0) {
    xQueueReceive(writeBuffer.CH1, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.CH2) > 0) {
    xQueueReceive(writeBuffer.CH2, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.CH3) > 0) {
    xQueueReceive(writeBuffer.CH3, &data, 0);
  }    
  while (uxQueueMessagesWaiting(writeBuffer.CH4) > 0) {
    xQueueReceive(writeBuffer.CH4, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.TIME) > 0) {
    xQueueReceive(writeBuffer.TIME, &data, 0);
  }

  vTaskDelete(TaskInjectHandle);
  vTaskDelete(TaskCompilerHandle);

  createTaskInject();
  createTaskCompiler();

  
}