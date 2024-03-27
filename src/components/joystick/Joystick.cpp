#include "Joystick.h"

Joystick::Joystick(int xPin, int yPin, int switchPin)
{
  this->xPin = xPin;
  this->yPin = yPin;
  this->switchPin = switchPin;
  pinMode(switchPin, INPUT_PULLUP);
}

float Joystick::map(float x, float inMin, float inMax, float outMin, float outMax)
{
  return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

float Joystick::convertRawValue(int raw, int center)
{
  if (raw > center)
  {
    return map(raw, center, 4095, 0, 1);
  }
  else
  {
    return map(raw, 0, center, -1, 0);
  }
}

int Joystick::getRawX()
{
  return analogRead(xPin);
}

int Joystick::getRawY()
{
  return analogRead(yPin);
}

float Joystick::getX()
{
  return convertRawValue(getRawX(), X_CENTER);
}

float Joystick::getY()
{
  return convertRawValue(getRawY(), Y_CENTER);
}

bool Joystick::isPressed()
{
  // digitalRead returns 0 when pressed, so flip it
  return !digitalRead(switchPin);
}

Direction Joystick::getDirection()
{
  float x = getX();
  float y = getY();
  float distance = sqrt(x * x + y * y);

  if (distance < JOYSTICK_DEADZONE)
  {
    return Direction::NONE;
  }
  else if (y <= x && y <= -x + 2)
  {
    return Direction::UP;
  }
  else if (y > x && y > -x + 2)
  {
    return Direction::DOWN;
  }
  else if (y > x && y < -x + 2)
  {
    return Direction::LEFT;
  }
  else
  {
    return Direction::RIGHT;
  }
}