#include <Timer.h>

hw_timer_t *My_timer = NULL;
BaseType_t xHigherPriorityTaskWoken = pdFALSE;

const float factor = 45.4167;
const uint32_t divisor = 1000000; // 1,000,000


void IRAM_ATTR timerISR() {
    
    timerRestart(My_timer);

    vTaskNotifyGiveFromISR(TaskInjectHandle, &xHigherPriorityTaskWoken);  // Notify the task
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);  // Perform a context switch if needed
    
}

void initTimer() {

    My_timer = timerBegin(0, 80, true);
    timerAttachInterrupt(My_timer, &timerISR, true);

}

void vMicrosecondsdelay(uint64_t us){

    timerAlarmWrite(My_timer, us, false);
    timerAlarmEnable(My_timer);

    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

}