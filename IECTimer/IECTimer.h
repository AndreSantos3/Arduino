#ifndef IECTimer_h
#define IECTimer_h
#include "Arduino.h"

class IECTimer
{
  public:
    IECTimer(unsigned long PT);
    bool Start;
    bool Reset;
    enum Type_t
    {
      Type_TON,
      Type_TOF,
      Type_TP,
      Type_TONR     
    };
    void Run();
    unsigned long ET(short Type);
    bool TON();
    bool TOF();
    bool TP();
    bool TONR();
    
  private:
    unsigned long _DifferenceMillis;
    unsigned long _LastMillis;
    unsigned long _TON_ET;
    unsigned long _TOF_ET;
    unsigned long _TP_ET;
    unsigned long _TONR_ET;
    unsigned long _PT;
};

#endif
