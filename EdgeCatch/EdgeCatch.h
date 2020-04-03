#ifndef EdgeCatch_h
#define EdgeCatch_h

#include "Arduino.h"

class EdgeCatch
{
  public:
    EdgeCatch(int pin);
    void attach();
    bool Rising();
    bool Falling();
  private:
    bool last_state;
    int _pin;
};

#endif
