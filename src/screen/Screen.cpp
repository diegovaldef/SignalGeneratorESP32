#include <Screen.h>
#include <ui.h>

TaskHandle_t TaskScreenHandle;
bool signalRunning = false;
bool firstOpen = true;

const char _DIRECTORY_ = '0';
const char _FILE_ = '1';

int selected;
byte ledsPin = 47;
byte relePin = 48;

void TaskScreen(void *pvParameters)
{
  while (true)
  {
    lv_timer_handler();
  }
}

void createTaskScreen()
{
  screenSetup();

  xTaskCreatePinnedToCore(
      TaskScreen,
      "TaskScreen",
      1024 * 10,
      NULL,
      2,
      &TaskScreenHandle,
      1);
}

void rollerUp(lv_event_t *e)
{

  if (lv_roller_get_selected(ui_Roller3) == 0)
  {
    lv_roller_set_selected(ui_Roller3, strlen(fileType) - 1, LV_ANIM_OFF);
  }
  else
  {

    uint32_t k = LV_KEY_UP;
    lv_event_send(ui_Roller3, LV_EVENT_KEY, &k);
  }
}

void rollerDown(lv_event_t *e)
{
  if (lv_roller_get_selected(ui_Roller3) == strlen(fileType) - 1)
  {
    lv_roller_set_selected(ui_Roller3, 0, LV_ANIM_OFF);
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
    resetSignal(e);
  }
  else
  {
    timerAlarmEnable(My_timer);
    timerStart(My_timer);
    vTaskResume(TaskCompilerHandle);
    vTaskResume(TaskInjectHandle);
    signalRunning = true;

    lv_obj_clear_flag(ui_Button7, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui_Button9, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui_Button11, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_set_style_border_width(ui_Button7, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Button6, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Button9, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Button11, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    showChannels();
  }
}

void openTarget(lv_event_t *e)
{

  selected = lv_roller_get_selected(ui_Roller3);

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
    refreshLabel();
  }
  else
  {
    _ui_screen_change(&ui_Loading, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 0, &ui_Loading_screen_init);
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
  refreshLabel();
}

void refreshLabel(){

  if (STR_Root == "/")
  {
    lv_label_set_text(ui_Label1, "Select a File");
  }
  else
  {
    lv_label_set_text(ui_Label1, STR_Root.c_str());
  }

}

void resetSignalComplete(lv_event_t *e)
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

  ch1 = 0;
  ch2 = 0;
  ch3 = 0;
  ch4 = 0;
  deltaTime = 0;

  uint64_t data;

  while (uxQueueMessagesWaiting(writeBuffer.CH1) > 0)
  {
    xQueueReceive(writeBuffer.CH1, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.CH2) > 0)
  {
    xQueueReceive(writeBuffer.CH2, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.CH3) > 0)
  {
    xQueueReceive(writeBuffer.CH3, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.CH4) > 0)
  {
    xQueueReceive(writeBuffer.CH4, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.TIME) > 0)
  {
    xQueueReceive(writeBuffer.TIME, &data, 0);
  }

  lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button9, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button11, LV_OBJ_FLAG_CLICKABLE);

  lv_obj_set_style_border_width(ui_Button7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_set_style_bg_opa(ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel4, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

  mcp.fastWrite(0, 0, 0, 0);

  vTaskDelete(TaskInjectHandle);
  vTaskDelete(TaskCompilerHandle);

  createTaskInject();
  createTaskCompiler();

}

void resetSignal(lv_event_t * e){

  timerAlarmDisable(My_timer); 
  timerStop(My_timer);
  vTaskSuspend(TaskCompilerHandle);
  vTaskSuspend(TaskInjectHandle);
  signalRunning = false;

  lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button9, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button11, LV_OBJ_FLAG_CLICKABLE);

  lv_obj_set_style_border_width(ui_Button7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_set_style_bg_opa(ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel4, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

  timerRestart(My_timer);

  uint64_t data;

  while (uxQueueMessagesWaiting(writeBuffer.CH1) > 0)
  {
    xQueueReceive(writeBuffer.CH1, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.CH2) > 0)
  {
    xQueueReceive(writeBuffer.CH2, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.CH3) > 0)
  {
    xQueueReceive(writeBuffer.CH3, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.CH4) > 0)
  {
    xQueueReceive(writeBuffer.CH4, &data, 0);
  }
  while (uxQueueMessagesWaiting(writeBuffer.TIME) > 0)
  {
    xQueueReceive(writeBuffer.TIME, &data, 0);
  }

  ch1 = 0;
  ch2 = 0;
  ch3 = 0;
  ch4 = 0;
  deltaTime = 0;

}

void refreshRollerButton(lv_event_t *e)
{
  refreshRoller();
}

void exitLogo(lv_event_t *e)
{
  SDBegin();

  if (!noSDFound)
  {
    _ui_screen_change(&ui_Explorador, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 3000, &ui_Explorador_screen_init);
  }
}

void AnimtoExplorer(lv_event_t *e)
{
  _ui_screen_change(&ui_Explorador, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 0, &ui_Explorador_screen_init);
}

void upFrecuency(lv_event_t * e)
{
  lv_spinbox_increment(ui_Spinbox2);
  frecuencyValue = lv_spinbox_get_value(ui_Spinbox2) / 100.0f;

}

void downFrecuency(lv_event_t * e)
{
  lv_spinbox_decrement(ui_Spinbox2);
  frecuencyValue = lv_spinbox_get_value(ui_Spinbox2) / 100.0f;
}

void upVoltage(lv_event_t * e)
{
  lv_spinbox_increment(ui_Spinbox1);
  voltageValue = lv_spinbox_get_value(ui_Spinbox1) / 100.0f;

}

void downVoltage(lv_event_t * e)
{
  lv_spinbox_decrement(ui_Spinbox1);
  voltageValue = lv_spinbox_get_value(ui_Spinbox1) / 100.0f;
}

void negativePositive(lv_event_t * e)
{
  bool state = lv_obj_has_state(ui_Switch1, LV_STATE_CHECKED);
  digitalWrite(ledsPin, state);

} 

void voltage5or12(lv_event_t * e){

  bool state = lv_obj_has_state(ui_Switch2, LV_STATE_CHECKED);
  digitalWrite(relePin, state);

}

void gotoPlot(lv_event_t * e){

  _ui_screen_change(&ui_Plot, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 0, &ui_Plot_screen_init);
  vTaskResume(TaskScopeHandle);
}

void backfromPlot(lv_event_t * e){ 
  vTaskSuspend(TaskScopeHandle);
}