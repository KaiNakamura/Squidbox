#include "Button.h"

Button::Button(int buttonPin)
{
   this->pin = buttonPin; // Declare the variable "pin"
   this->pressed = false; 
   pinMode(pin, INPUT);
}

void Button::loop() {
    digitalWrite(this->pin, HIGH); 
    delay(1000);            
    digitalWrite(this->pin, LOW);  
    delay(1000);            
}