#include <Screen.h>

TaskHandle_t TaskScreenHandle;
bool signalRunning = false;
bool firstOpen = true;

const char _DIRECTORY_ = '0';
const char _FILE_ = '1';

void TaskScreen(void *pvParameters){
  while(true){
    lv_timer_handler();
    vTaskDelay(5);
  }
}

void createTaskScreen(){

  xTaskCreatePinnedToCore(
      TaskScreen,
      "TaskScreen",
      1024 * 10,
      NULL,
      1,
      &TaskScreenHandle,
      1);

}

void rollerUp(lv_event_t * e)
{

  if(lv_roller_get_selected(ui_Roller3) == 0){
    lv_roller_set_selected(ui_Roller3, 2, LV_ANIM_ON);

  }
  else {

    uint32_t k = LV_KEY_UP;
    lv_event_send(ui_Roller3, LV_EVENT_KEY, &k);

  }

}

void rollerDown(lv_event_t * e)
{
  if(lv_roller_get_selected(ui_Roller3) == 2){
    lv_roller_set_selected(ui_Roller3, 0, LV_ANIM_ON);

  }
  else {

    uint32_t k = LV_KEY_DOWN;
	  lv_event_send(ui_Roller3, LV_EVENT_KEY, &k);

  }

}

void SignalStartStop(lv_event_t * e)
{
  if(signalRunning){
    vTaskSuspend(TaskInjectHandle);
    vTaskSuspend(TaskCompilerHandle);
    timerStop(My_timer);
    timerAlarmDisable(My_timer);
    signalRunning = false;
    
  }
  else{
    vTaskResume(TaskInjectHandle);
    vTaskResume(TaskCompilerHandle);
    timerStart(My_timer);
    timerAlarmEnable(My_timer);
    signalRunning = true;
    
  }

}

void openTarget(lv_event_t * e)
{ 
  byte selected = lv_roller_get_selected(ui_Roller3);

  if(firstOpen){
    STR_Root = fileName[selected];
    firstOpen = false;
  }
  else{
    STR_Root = STR_Root + fileName[selected];
  }

	if(fileType[selected] == _DIRECTORY_){
    refreshRoller();
  }
  else{
    _ui_screen_change(&ui_Loading, LV_SCR_LOAD_ANIM_FADE_ON, 0 , 0, &ui_Loading_screen_init);
    vTaskResume(TaskCompilerHandle);
  }

}