#include <Screen.h>

const char _DIRECTORY_ = '0';
const char _FILE_ = '1';

int selected;
bool firstOpen = true;

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
    globalStates.compiler = true;
    reloadTasks();
  }
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

void refreshRollerButton(lv_event_t *e)
{
  refreshRoller();
}

void gotoPlot(lv_event_t * e){

  _ui_screen_change(&ui_Plot, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 0, &ui_Plot_screen_init);
  globalStates.scope = true;
  reloadTasks();
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