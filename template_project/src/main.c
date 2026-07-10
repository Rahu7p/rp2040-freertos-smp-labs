#include "main.h"

TaskHandle_t TaskAHandle = NULL;
TaskHandle_t TaskBHandle = NULL;    

void TaskA(void *pvParameters);
void TaskB(void *pvParameters);

int main()
{
    stdio_init_all();
    sleep_ms(2000);   // Esperar a que el puerto USB CDC esté listo

    xTaskCreate( TaskA, "TaskA", 256, NULL, tskIDLE_PRIORITY + 1, &TaskAHandle);
    xTaskCreate( TaskB, "TaskB", 256, NULL, tskIDLE_PRIORITY + 1, &TaskBHandle);

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
void TaskB(void *pvParameters) {

    while (1) {
        printf("Task B\r\n");
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
