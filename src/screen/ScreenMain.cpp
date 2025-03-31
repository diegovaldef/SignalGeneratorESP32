#include <Screen.h>

byte ledsPin = 47;
byte relePin = 48;
bool signalRunning = false;

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

    globalStates.compiler = true;
    globalStates.inject = true;
    reloadTasks();

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

void resetSignalComplete(lv_event_t *e)
{

  globalStates.compiler = false;
  globalStates.inject = false;
  reloadTasks();

  Serial.println("a");

  timerAlarmDisable(My_timer);
  Serial.println("b");

  timerStop(My_timer);
  Serial.println("c");

  timerDetachInterrupt(My_timer);
  Serial.println("d");

  timerEnd(My_timer);
  Serial.println("e");

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

  Serial.println("f");

  lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button9, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button11, LV_OBJ_FLAG_CLICKABLE);

  Serial.println("g");

  lv_obj_set_style_border_width(ui_Button7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  Serial.println("h");

  lv_obj_set_style_bg_opa(ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel4, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

  Serial.println("i");

  mcp.fastWrite(0, 0, 0, 0);

  Serial.println("j");

  vTaskDelete(TaskInjectHandle);
  Serial.println("k");

  vTaskDelete(TaskCompilerHandle);
  Serial.println("l");

  createTaskInject();
  Serial.println("m");

  createTaskCompiler();
  Serial.println("n");

}

void resetSignal(lv_event_t * e){

  timerAlarmDisable(My_timer); 
  timerStop(My_timer);

  globalStates.compiler = false;
  globalStates.inject = false;
  reloadTasks();

  Serial.println("a");

  signalRunning = false;

  lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button9, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_Button11, LV_OBJ_FLAG_CLICKABLE);

  Serial.println("b");

  lv_obj_set_style_border_width(ui_Button7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_Button11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  Serial.println("c");

  lv_obj_set_style_bg_opa(ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Panel4, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

  Serial.println("d");

  timerRestart(My_timer);

  Serial.println("e");

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

  Serial.println("f");

  ch1 = 0;
  ch2 = 0;
  ch3 = 0;
  ch4 = 0;
  deltaTime = 0;

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

void AnimtoExplorer(lv_event_t *e)
{
  _ui_screen_change(&ui_Explorador, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 0, &ui_Explorador_screen_init);
}

void showChannels()
{

  if(maxCH1 != 0){
    lv_obj_set_style_bg_opa(ui_Panel1, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else {
    lv_obj_set_style_bg_opa(ui_Panel1, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  if(maxCH2 != 0){
    lv_obj_set_style_bg_opa(ui_Panel2, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT); 
  }
  else{
    lv_obj_set_style_bg_opa(ui_Panel2, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  if(maxCH3 != 0){
    lv_obj_set_style_bg_opa(ui_Panel3, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else{
    lv_obj_set_style_bg_opa(ui_Panel3, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  if(maxCH4 != 0){
    lv_obj_set_style_bg_opa(ui_Panel4, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else{
    lv_obj_set_style_bg_opa(ui_Panel4, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

}