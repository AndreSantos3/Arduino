/* This example shows how to make a delay using the IEC TOF
The timer time (ET) rises after the Start goes false and Reset is false
When the defined time (PT) is lower than the rising time, the output is false

          TOF time diagram
.........................................
      .        +---+        +---+ +---- .
Start .        |   |        |   | |     .
      .      --+   +--------+   +-+     .
.........................................     
      .        +--------+   +---------- .
TOF   .        |        |   |           .
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
Imagine that you need to activate an output if a square wave of 1hz is detected
This timer will act like a bypass to the square wave
*/
#include "IECTimer.h"

// Timer value in ms
// You can have the timers you want, the limit is the arduino memory
IECTimer TOF(1000);

void setup()
{

  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop()
{
  // Use this function to refresh the timer
  TOF.Run();
  // The timer will start counting while when the Start goes from True to False
  TOF.Start = digitalRead(4);
  // The timer will be set to 0 when Reset is True
  TOF.Reset = digitalRead(5);
  // When 1000ms passed since the Start is false, the TOF goes False
  if(TOF.TOF())
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  // Show the variables on the serial. The ET function shows the actual timer time
  // The IECTimer::Type_TOF represents an enum value to the timer type
  Serial.print(TOF.ET(IECTimer::Type_TOF)); 
  Serial.print(" ");
  // Timer Start status
  if(TOF.Start)
    Serial.println("Start = TRUE");
  else
    Serial.println("Start = FALSE"); 
}
