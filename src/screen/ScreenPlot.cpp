#include <Screen.h>

void backfromPlot(lv_event_t * e){ 
  globalStates.scope = false;
  reloadTasks();
}