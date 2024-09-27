
#ifndef OS_H
#define OS_H


/*      INCLUDES     */
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
#include "..\glob.h"


/*      DEFINES     */
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


/*      VARIABLES     */
extern byte initApp;
extern byte iOsAppErr;

extern SemaphoreHandle_t xMutex;


extern TaskHandle_t tTask100ms;
extern TaskHandle_t tTask1s;
extern TaskHandle_t tSoftIrq;

// extern SemaphoreHandle_t xMutex /*xRadioIrqSemaphore*/;
//extern SemaphoreHandle_t xMutex /*xRadioMutex*/;
//extern SemaphoreHandle_t xMutex /*xConsoleMutex*/ ;
extern QueueHandle_t xPayloadQueue;
extern QueueHandle_t xStatusQueue;


/*      FUNCTIONS     */
extern void OsInit();

extern void OsTask100ms( void *pvParameters );
extern void OsTask1s( void *pvParameters );
extern void OsTaskSoftIrq(void* pvParameters);

extern void OsCreateTasks();
extern byte  OsAddHandlers();

extern void irq_handler_com(void);
extern void irq_handler_dio(void);

#endif