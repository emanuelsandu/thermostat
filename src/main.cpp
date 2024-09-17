
#include <Arduino.h>
#include "..\include\aio\aio.h"
#include "..\include\com\com.h"
#include "..\include\dio\dio.h"
#include "..\include\disp\disp.h"
#include "..\include\os\os.h"
#include"..\include\config.h"
#include "..\include\ui\ui.h"



// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600);
  
  while (!Serial) {
  }

  // Semaphores are useful to stop a Task proceeding, where it should be paused to wait,
  // because it is sharing a resource, such as the Serial port.
  // Semaphores should only be used whilst the scheduler is running, but we can set it up here.
  createTasks();
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/
