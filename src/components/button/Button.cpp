#include "Button.h"

Button::Button(int pin) : pin(pin) {
  pinMode(pin, INPUT_PULLUP);
  wasDown = false;
  wasUp = true;
}

bool Button::isDown() {
  // The digitalRead function returns HIGH if the button is not pressed, and LOW
  // if it is. Therefore, we need to negate its result to get the correct value.
  return !digitalRead(pin);
}

bool Button::isPressed() {
  bool down = isDown(); // Check if the button is currently being pressed.

  // If the button is currently being pressed and was not being pressed the last
  // time we checked, then the button was just pressed.
  bool pressed = down && !wasDown;

  wasDown = down; // Update the wasDown variable for the next time we check.

  return pressed;
}

bool Button::isReleased() {
  bool up = !isDown(); // Check if the button is currently not being pressed.

  // If the button is currently not being pressed and was being pressed the last
  // time we checked, then the button was just released.
  bool released = up && !wasUp;

  wasUp = up; // Update the wasUp variable for the next time we check.

  return released;
}