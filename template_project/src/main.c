#include "main.h"

TaskHandle_t TaskAHandle = NULL;  

void TaskA(void *pvParameters);

int main()
{
    stdio_init_all();
    sleep_ms(2000);

    xTaskCreate( TaskA, "TaskA", 256, NULL, tskIDLE_PRIORITY + 1, &TaskAHandle);

    printf("Starting Scheduler...\r\n");

    vTaskStartScheduler();

    while (1) {

    }
}

/*--------------------------------------------------------------------*/

void TaskA(void *pvParameters) {
    
    while (1) {
        printf("Task A\r\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    (void)xTask;
    (void)pcTaskName;

    while (1) {

    }
}

/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook(void)
{
    while (1) {

    }
}
