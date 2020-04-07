#include "Arduino.h"
#include "IECTimer.h"

IECTimer::IECTimer(unsigned long PT)
{
  _DifferenceMillis = 0;
  _LastMillis = 0;
  _TON_ET = 0;
  _TOF_ET = 0;
  _TP_ET = 0;
  _TONR_ET = 0;
  _PT = PT;
  Start = false;
  Reset = false;
}
void IECTimer::Run()
{
  _DifferenceMillis = millis() - _LastMillis;
  _LastMillis = millis();
  if(Start)
  {
    _TON_ET += _DifferenceMillis;
    _TP_ET += _DifferenceMillis;
    _TOF_ET += _DifferenceMillis;
    _TONR_ET += _DifferenceMillis;
  }
  else
  {
    _TON_ET = 0;
    _TP_ET = 0;
    _TOF_ET = 0;
  }
  if(Reset)
  {
    _TON_ET = 0;
    _TOF_ET = 0;
    _TP_ET = 0;
    _TONR_ET = 0;
  }
}
unsigned long IECTimer::ET(short Type)
{
  switch(Type)
  {
    case Type_TON:
      return _TON_ET;
      break;
    case Type_TOF:
      return _TOF_ET;
      break;
    case Type_TP:
      return _TP_ET;
      break;
    case Type_TONR:
      return _TONR_ET;
      break;
  }
}
bool IECTimer::TON()
{
  if(_TON_ET >= _PT)
    return true;
  else
    return false;
}
bool IECTimer::TOF()
{
  if(_TOF_ET <= _PT)
    return true;
  else
    return false;
}
bool IECTimer::TP()
{
  if(_TP_ET <= _PT)
    return true;
  else
    return false;
}
bool IECTimer::TONR()
{
  if(_TONR_ET >= _PT)
    return true;
  else
    return false;
}
