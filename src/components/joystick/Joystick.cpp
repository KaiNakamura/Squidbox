#include "Joystick.h"

Joystick::Joystick(int xPin, int yPin, int switchPin)
{
   this->xPin = xPin;
   this->yPin = yPin;
   this->switchPin = switchPin;
   pinMode(xPin, INPUT);
   pinMode(yPin, INPUT);
   pinMode(switchPin, INPUT_PULLUP); // Open switch, connects to ground on press
}

void Joystick::readValues() 
{
   this->xValue = analogRead(this->xPin);
   this->yValue = analogRead(this->yPin);
   this->switchValue = digitalRead(this->switchPin);
}