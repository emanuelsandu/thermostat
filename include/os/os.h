
#ifndef OS_H
#define OS_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
#include "..\glob.h"

#define __OS_STATUS_OK__                        0
#define __OS_STATUS_INIT_FAIL__                 1

#define __OS_STATUS_TASK_COM_TX_OK__            2
#define __OS_STATUS_TASK_COM_TX_INIT_FAIL__     4
#define __OS_STATUS_TASK_COM_TX_FAIL__          8

#define __OS_STATUS_TASK_COM_RX_OK__            16
#define __OS_STATUS_TASK_COM_RX_INIT_FAIL__     32
#define __OS_STATUS_TASK_COM_RX_FAIL__          64

#define __OS_STATUS_GEN_FAIL__                  255


#define configBlockResTickPeriod 1

#define Task10msPeriod      10
#define Task100msPeriod     100
#define Task1000msPeriod    1000

extern int initApp;

extern SemaphoreHandle_t xSerialSemaphore;
extern TaskHandle_t tTaskInit;
extern TaskHandle_t tTaskOneCycle;
extern TaskHandle_t tTask100ms;
extern TaskHandle_t tTask1s;
extern TaskHandle_t tComSoftIrq;
extern TaskHandle_t tComRxTask;
extern TaskHandle_t tComTxTask;
extern TaskHandle_t tComStatus;
extern TaskHandle_t tDbgIn;

extern SemaphoreHandle_t xRadioIrqSemaphore;
extern SemaphoreHandle_t xRadioMutex;
extern SemaphoreHandle_t xConsoleMutex;
extern QueueHandle_t xPayloadQueue;
extern QueueHandle_t xStatusQueue;


extern void OsInit();
extern void vTaskInit( void *pvParameters );
extern void vTaskOneCycle( void *pvParameters );
extern void vTask100ms( void *pvParameters );
extern void vTask1s( void *pvParameters );

extern void vSenderTask(void* pvParameters);
extern void vReceiverTask(void* pvParameters);
extern void vStatusTask(void* pvParameters);
extern void vInputTask(void* pvParameters);
extern void vRadioSoftIrqTask(void* pvParameters);
extern void setup_radio(void);
extern void radio_set_role(int newrole);

extern void vOsCreateTasks();

#endif