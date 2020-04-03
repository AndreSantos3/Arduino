#include "EdgeCatch.h"

// Enter the pin number
// Example: pin 4
EdgeCatch RisingEdge4(4);

int counter;

void setup()
{
    // Initialize the variables
    RisingEdge4.attach();
}

void loop()
{
  // The method Rising() gives the rising edge of the pin
  if(RisingEdge4.Rising())
  {
    counter += 1;
  }
}
