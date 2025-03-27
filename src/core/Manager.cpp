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
        1,
        &TaskManagerHandle,
        1);
}

void TaskManager(void *pvParameters)
{
    vTaskSuspend(TaskManagerHandle);

    while (true)
    {
        if (!globalStates.compilerState)
        {
            while(eTaskGetState(TaskCompilerHandle) != eSuspended)
            {
                vTaskSuspend(TaskCompilerHandle);
                vTaskDelay(1);
            }
        }
        else
        {
            while(eTaskGetState(TaskCompilerHandle) == eSuspended)
            {
                vTaskResume(TaskCompilerHandle);
                vTaskDelay(1);
            }
        }

        if (!globalStates.injectState)
        {
            while(eTaskGetState(TaskInjectHandle) != eSuspended)
            {
                vTaskSuspend(TaskInjectHandle);
                vTaskDelay(1);
            }
        }
        else
        {
            while(eTaskGetState(TaskInjectHandle) == eSuspended)
            {
                vTaskResume(TaskInjectHandle);
                vTaskDelay(1);
            }
        }

        if (!globalStates.sdState)
        {
            while(eTaskGetState(TaskSDHandle) != eSuspended)
            {
                vTaskSuspend(TaskSDHandle);
                vTaskDelay(1);
            }
        }
        else
        {
            while(eTaskGetState(TaskSDHandle) == eSuspended)
            {
                vTaskResume(TaskSDHandle);
                vTaskDelay(1);
            }
        }

        if (!globalStates.plotState)
        {
            while(eTaskGetState(TaskScopeHandle) != eSuspended)
            {
                vTaskSuspend(TaskScopeHandle);
                vTaskDelay(1);
            }
        }
        else
        {
            while(eTaskGetState(TaskScopeHandle) == eSuspended)
            {
                vTaskResume(TaskScopeHandle);
                vTaskDelay(1);
            }
        }

        vTaskSuspend(TaskManagerHandle);
    }
}
