/* This example shows how to make a delay using the IEC TP
The timer time (ET) rises after the Start goes true
The output will mantain true while the time(ET) is lower than the defined time

          TP time diagram
.........................................
      .        +---+        +---+ +---- .
Start .        |   |        |   | |     .
      .      --+   +--------+   +-+     .
.........................................     
      .        +--------+   +---------- .
TP    .        |        |   |           .
      .      --+        +---+           .
.........................................
      . PT          +---+               .
      .            /    |               .
      .           /     |               .
ET    . PT/2     /      |         +     .
      .         /       |        /|     .
      . 0    --+        +-------+ +---- .
.........................................

#######  USES OF THIS TIMER ################
This time is really simple to understand, just gives a pulse after the Start goes True
*/
#include "IECTimer.h"

// Timer value in ms
// You can have the timers you want, the limit is the arduino memory
IECTimer TP(1000);

void setup()
{

}

void loop()
{
  // Use this function to refresh the timer
  TP.Run();
  // The timer will start counting while when the Start goes True
  TP.Start = digitalRead(4);
  // The timer will be set to 0 when Reset is True
  TP.Reset = digitalRead(5);
  // When 1000ms passed since the Start, the TP goes False
  if(TP.TP())
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
}
