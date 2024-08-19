#include <Arduino.h>

#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>

void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p );
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data );
void screenSetup();
void rollerUp(lv_event_t * e);
void rollerDown(lv_event_t * e);
