#include <Manager.h>

taskStates globalStates;
TaskHandle_t TaskManagerHandle;

void reloadTasks(){
    vTaskResume(TaskManagerHandle);
}

void createTaskManager()
{
    xTaskCreatePinnedToCore(
        TaskManager,
        "TaskManager",
        1024 * 10,
        NULL,
        10,
        &TaskManagerHandle,
        0);
}

void TaskManager(void *pvParameters)
{
    vTaskSuspend(TaskManagerHandle);

    while (true)
    {
        //if (!globalStates.compiler) vTaskSuspend(TaskCompilerHandle); else vTaskResume(TaskCompilerHandle);
        //if (!globalStates.inject) vTaskSuspend(TaskInjectHandle); else vTaskResume(TaskInjectHandle);
        //if (!globalStates.sd) vTaskSuspend(TaskSDHandle); else vTaskResume(TaskSDHandle);
        //if (!globalStates.scope) vTaskSuspend(TaskScopeHandle); else vTaskResume(TaskScopeHandle);

        if (!globalStates.compiler)
        {
            while(eTaskGetState(TaskCompilerHandle) != eSuspended)
            {
                vTaskSuspend(TaskCompilerHandle);
                Serial.println("Compiler suspended");
                vTaskDelay(1);
            }
        }
        else
        {
            while(eTaskGetState(TaskCompilerHandle) == eSuspended)
            {
                vTaskResume(TaskCompilerHandle);
                Serial.println("Compiler resumed");
                vTaskDelay(1);
            }
        }

        if (!globalStates.inject)
        {
            while(eTaskGetState(TaskInjectHandle) != eSuspended)
            {
                vTaskSuspend(TaskInjectHandle);
                Serial.println("Inject suspended");
                vTaskDelay(1);
            }
        }
        else
        {
            while(eTaskGetState(TaskInjectHandle) == eSuspended)
            {
                vTaskResume(TaskInjectHandle);
                Serial.println("Inject resumed");
                vTaskDelay(1);
            }
        }

        if (!globalStates.sd)
        {
            while(eTaskGetState(TaskSDHandle) != eSuspended)
            {
                vTaskSuspend(TaskSDHandle);
                Serial.println("SD suspended");
                vTaskDelay(1);
            }
        }
        else
        {
            while(eTaskGetState(TaskSDHandle) == eSuspended)
            {
                vTaskResume(TaskSDHandle);
                Serial.println("SD resumed");
                vTaskDelay(1);
            }
        }

        if (!globalStates.scope)
        {
            while(eTaskGetState(TaskScopeHandle) != eSuspended)
            {
                vTaskSuspend(TaskScopeHandle);
                Serial.println("Scope suspended");
                vTaskDelay(1);
            }
        }
        else
        {
            while(eTaskGetState(TaskScopeHandle) == eSuspended)
            {
                vTaskResume(TaskScopeHandle);
                Serial.println("Scope resumed");
                vTaskDelay(1);
            }
        }

        vTaskSuspend(TaskManagerHandle);
    }
}
