#include "Arduino.h"
#include "EdgeCatch.h"

EdgeCatch::EdgeCatch(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}
void EdgeCatch::attach()
{
  last_state = digitalRead(_pin);
}
bool EdgeCatch::Rising()
{
  if(digitalRead(_pin) == HIGH && last_state == false)
  {
    last_state = true;
    return true;
  }
  else if(digitalRead(_pin) == HIGH && last_state == true)
  {
    return false;
  }
  else
  {
    last_state = false;
    return false;
  }
}
bool EdgeCatch::Falling()
{
  if(digitalRead(_pin) == LOW && last_state == false) 
  {
    last_state = true;
    return true;
  }
  else if(digitalRead(_pin) == LOW && last_state == true)
  {
    return false;
  }
  else
  {
    last_state = false;
    return false;
  }
}
