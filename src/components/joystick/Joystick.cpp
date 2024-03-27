#include "Joystick.h"

Joystick::Joystick(int xPin, int yPin, int switchPin)
{
  this->xPin = xPin;
  this->yPin = yPin;
  this->switchPin = switchPin;
  pinMode(switchPin, INPUT_PULLUP);
}

float Joystick::convertRawValue(int raw)
{
  return 2 * (raw / 4096.0) - 1;
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
  return convertRawValue(getRawX());
}

float Joystick::getY()
{
  return convertRawValue(getRawY());
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