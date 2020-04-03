#include "EdgeCatch.h"

// Enter the pin number
// Example: pin 4
EdgeCatch FallingEdge4(4);

int counter;

void setup()
{
    // Initialize the variables
    FallingEdge4.attach();
}

void loop()
{
  // The method Falling() gives the rising edge of the pin
  if(FallingEdge4.Falling())
  {
    counter += 1;
  }
}
