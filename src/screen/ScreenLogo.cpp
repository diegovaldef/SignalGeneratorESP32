#include <Screen.h>

void exitLogo(lv_event_t *e)
{
  SDBegin();

  if (!noSDFound)
  {
    _ui_screen_change(&ui_Explorador, LV_SCR_LOAD_ANIM_FADE_OUT, 0, 3000, &ui_Explorador_screen_init);
  }
}
