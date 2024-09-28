#include"..\include\glob.h"

// the setup function runs once when you press reset or power the board
void setup() {

    OsInit();

    OsCreateTasks();

    /* Start the scheduler. */
    vTaskStartScheduler();

}

void loop()
{
  // Empty. Things are done in Tasks.
}
