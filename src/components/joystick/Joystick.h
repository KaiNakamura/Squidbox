#pragma once 

#include <Arduino.h>
#include "config/config.h"
#include "config/pins.h"

class Joystick 
{
   public: 
      Joystick(int xPin, int yPin, int switchPin);
      void readValues();
   
   private:
      int xPin;
      int yPin;
      int switchPin;
      int xValue;
      int yValue;
      int switchValue;
};