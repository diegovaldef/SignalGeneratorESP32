#include <Screen.h>

TaskHandle_t TaskScreenHandle;

void TaskScreen(void *pvParameters){
  while(true){
    lv_timer_handler();
  }
}

void createTaskScreen(){

  xTaskCreatePinnedToCore(
      TaskScreen,
      "TaskScreen",
      1024 * 5,
      NULL,
      2,
      &TaskScreenHandle,
      0);

}

void rollerUp(lv_event_t * e)
{

  if(lv_roller_get_selected(ui_Roller3) == 0){
    lv_roller_set_selected(ui_Roller3, 3, LV_ANIM_ON);

  }
  else {

    uint32_t k = LV_KEY_UP;
    lv_event_send(ui_Roller3, LV_EVENT_KEY, &k);

  }

}

void rollerDown(lv_event_t * e)
{
  if(lv_roller_get_selected(ui_Roller3) == 3){
    lv_roller_set_selected(ui_Roller3, 0, LV_ANIM_ON);

  }
  else {

    uint32_t k = LV_KEY_DOWN;
	  lv_event_send(ui_Roller3, LV_EVENT_KEY, &k);

  }

}
