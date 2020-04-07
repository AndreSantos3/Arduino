/* This example shows how to make a delay using the IEC TON
The timer time (ET) rises while the Start is true and Reset is false
When the defined time (PT) is lower than the rising time, the output is true

          TON time diagram
.........................................
      .        +--------+       +-+     .
Start .        |        |       | |     .
      .      --+        +-------+ +---  .
.........................................     
      .             +---+               .
TON   .             |   |               .
      .      -------+   +-------------  .
.........................................
      . PT          +---+               .
      .            /    |               .
      .           /     |               .
ET    . PT/2     /      |         +     .
      .         /       |        /|     .
      . 0    --+        +-------+ +---  .
.........................................

#######  USES OF THIS TIMER ################
Imagine that you need to change an output 1s after an input is true
This timer will act like an activation delay
*/
#include "IECTimer.h"

// Timer value in ms
// You can have the timers you want, the limit is the arduino memory
IECTimer TON(1000);

void setup()
{

  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop()
{
  // Use this function to refresh the timer
  TON.Run();
  // The timer will be counting while Start is True
  TON.Start = digitalRead(4);
  // The timer will be set to 0 when Reset is True
  TON.Reset = digitalRead(5);
  // When 1000ms passed since the Start is on, the TON goes True
  if(TON.TON())
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  // Show the variables on the serial. The ET function shows the actual timer time
  // The IECTimer::Type_TON represents an enum value to the timer type
  Serial.print(TON.ET(IECTimer::Type_TON)); 
  Serial.print(" ");
  // Timer Start status
  if(TON.Start)
    Serial.println("Start = TRUE");
  else
    Serial.println("Start = FALSE"); 
}
