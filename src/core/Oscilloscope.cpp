#include <Oscilloscope.h>

TaskHandle_t TaskScopeHandle;
Adafruit_ADS1015 ads;
lv_chart_series_t *ser[4];

float adc0 = 0;
float adc1 = 0;
float adc2 = 0;
float adc3 = 0;

lv_color_t colors[] = {
    lv_palette_main(LV_PALETTE_RED),
    lv_palette_main(LV_PALETTE_BLUE),
    lv_palette_main(LV_PALETTE_GREEN),
    lv_palette_main(LV_PALETTE_YELLOW)
};

void createTaskScope()
{
    for (int i = 0; i < 4; i++)
    {
        ser[i] = lv_chart_add_series(ui_Chart1, colors[i], LV_CHART_AXIS_PRIMARY_Y);
    }

    lv_chart_set_update_mode(ui_Chart1, LV_CHART_UPDATE_MODE_CIRCULAR);

    ads.begin();
    ads.setGain(GAIN_TWOTHIRDS);

    xTaskCreatePinnedToCore(
        TaskScope,
        "TaskScope",
        1024 * 10,
        NULL, 
        14,
        &TaskScopeHandle,
        0);

    vTaskSuspend(TaskScopeHandle);
}

void TaskScope(void *pvParameters)
{
    while (true)
    {
        adc0 = ads.computeVolts(ads.readADC_SingleEnded(0));
        adc1 = ads.computeVolts(ads.readADC_SingleEnded(1));
        adc2 = ads.computeVolts(ads.readADC_SingleEnded(2));
        adc3 = ads.computeVolts(ads.readADC_SingleEnded(3));

        //Serial.println(adc0);
        //Serial.println(adc1);
        //Serial.println(adc2);
        //Serial.println(adc3);

        lv_chart_set_next_value(ui_Chart1, ser[0], adc0);
        lv_chart_set_next_value(ui_Chart1, ser[1], adc1);
        lv_chart_set_next_value(ui_Chart1, ser[2], adc2);
        lv_chart_set_next_value(ui_Chart1, ser[3], adc3);

        vTaskDelay(1);
    }
}

