/* This example shows how to make a time acomulator using the IEC TONR
The timer time (ET) rises while the Start is True, if the timer will be set to 0 only with Reset
When the defined time (PT) is lower than the rising time, the output is true

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
Imagine that you need to monitor oh much time an input is true during a minute
If the total time is bigger than 30s you want to activate an output and increment a counter
This example will show how to do it
*/
#include "IECTimer.h"

// Timer value in ms
// You can have the timers you want, the limit is the arduino memory
IECTimer TONR_1(30000);   // Timer overflow 30s
IECTimer TONR_2(60000);   // Timer overflow 60s
int counter;

void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop()
{
  // Use this function to refresh the timer
  TONR_1.Run();
  TONR_2.Run();
  // The timer will be start counting if the start is true
  TONR_1.Start = digitalRead(4);
  TONR_2.Start = true;
  // If the sum of all time of the timer is bigger than 30s, the TONR goes True
  if(TONR_1.TONR())
  {
    digitalWrite(13, HIGH);
    counter += 1;
  }
  else
    digitalWrite(13, LOW);
  // After the 60s the timers are reset to start agin the monitoring
  if(TONR_2.TONR())
  {
    TONR_1.Reset;
    TONR_2.Reset;
  }
  // Show the variables on the serial. The ET function shows the actual timer time
  // The IECTimer::Type_TONR represents an enum value to the timer type
  Serial.print(TONR_1.ET(IECTimer::Type_TONR)); 
  Serial.print(" ");
  Serial.print(TONR_2.ET(IECTimer::Type_TONR)); 
  Serial.print(" ");
  // Timer Start status
  if(TONR_1.Start)
    Serial.println("Start = TRUE");
  else
    Serial.println("Start = FALSE"); 
}
