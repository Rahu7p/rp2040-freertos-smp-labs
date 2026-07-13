#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <assert.h>
#include <stdint.h>

/*-----------------------------------------------------------
 * Hardware
 *----------------------------------------------------------*/
#define configCPU_CLOCK_HZ                     ( 125000000UL )
#define configTICK_RATE_HZ                     ( (TickType_t)1000 )
#define configNUMBER_OF_CORES                  1
/*-----------------------------------------------------------
 * Scheduler
 *----------------------------------------------------------*/
#define configUSE_PREEMPTION                   1
#define configUSE_TIME_SLICING                 1
#define configMAX_PRIORITIES                   8
#define configMINIMAL_STACK_SIZE               256
#define configMAX_TASK_NAME_LEN                16
#define configUSE_16_BIT_TICKS                 0
#define configIDLE_SHOULD_YIELD                1
/*-----------------------------------------------------------
 * SMP
 *----------------------------------------------------------*/
#define configUSE_CORE_AFFINITY                1
#define configRUN_MULTIPLE_PRIORITIES          1
#define configUSE_PASSIVE_IDLE_HOOK            0
#define configTICK_CORE                        0
/*-----------------------------------------------------------
 * Memory
 *----------------------------------------------------------*/
#define configSUPPORT_STATIC_ALLOCATION        0
#define configSUPPORT_DYNAMIC_ALLOCATION       1
#define configTOTAL_HEAP_SIZE                  (128 * 1024)
#define configAPPLICATION_ALLOCATED_HEAP       0
/*-----------------------------------------------------------
 * Synchronization
 *----------------------------------------------------------*/
#define configUSE_MUTEXES                      1
#define configUSE_RECURSIVE_MUTEXES            1
#define configUSE_COUNTING_SEMAPHORES          1
#define configUSE_QUEUE_SETS                   1
#define configQUEUE_REGISTRY_SIZE              8
/*-----------------------------------------------------------
 * Software Timers
 *----------------------------------------------------------*/
#define configUSE_TIMERS                       1
#define configTIMER_TASK_PRIORITY              (configMAX_PRIORITIES - 1)
#define configTIMER_QUEUE_LENGTH               10
#define configTIMER_TASK_STACK_DEPTH           512
/*-----------------------------------------------------------
 * Hooks
 *----------------------------------------------------------*/
#define configUSE_IDLE_HOOK                    0
#define configUSE_TICK_HOOK                    0
#define configCHECK_FOR_STACK_OVERFLOW         2
#define configUSE_MALLOC_FAILED_HOOK           1
/*-----------------------------------------------------------
 * Statistics
 *----------------------------------------------------------*/
#define configUSE_TRACE_FACILITY               1
#define configGENERATE_RUN_TIME_STATS          0
#define configUSE_STATS_FORMATTING_FUNCTIONS   0
/*-----------------------------------------------------------
 * RP2040
 *----------------------------------------------------------*/
#define configSUPPORT_PICO_SYNC_INTEROP        1
#define configSUPPORT_PICO_TIME_INTEROP        1
/*-----------------------------------------------------------
 * Assertions
 *----------------------------------------------------------*/
#define configASSERT(x)                        assert(x)
/*-----------------------------------------------------------
 * API Inclusion
 *----------------------------------------------------------*/
#define INCLUDE_vTaskPrioritySet               1
#define INCLUDE_uxTaskPriorityGet              1
#define INCLUDE_vTaskDelete                    1
#define INCLUDE_vTaskSuspend                   1
#define INCLUDE_vTaskDelay                     1
#define INCLUDE_vTaskDelayUntil                1
#define INCLUDE_vTaskSuspend                   1
#define INCLUDE_xTaskAbortDelay                1
#define INCLUDE_xTaskGetCurrentTaskHandle      1
#define INCLUDE_xTaskGetSchedulerState         1
#define INCLUDE_xTaskGetIdleTaskHandle         1
#define INCLUDE_xTaskGetHandle                 1
#define INCLUDE_xTaskResumeFromISR             1
#define INCLUDE_eTaskGetState                  1
#define INCLUDE_xTimerPendFunctionCall         1

#endif /* FREERTOS_CONFIG_H */
