#pragma once

#include <Arduino.h>
#include "config/config.h"
#include "config/pins.h"

class Button
{
public:    
   bool pressed;
   int pin;   
   Button(int buttonPin);   
   void loop();
};