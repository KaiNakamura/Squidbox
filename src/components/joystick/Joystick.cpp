#include "Joystick.h"

const char *directionToString(Direction direction)
{
  switch (direction)
  {
  case NONE:
    return "NONE";
  case UP:
    return "UP";
  case RIGHT:
    return "RIGHT";
  case DOWN:
    return "DOWN";
  case LEFT:
    return "LEFT";
  default:
    return "UNKNOWN";
  }
}

Joystick::Joystick(int xPin, int yPin, int buttonPin)
{
  this->xPin = xPin;
  this->yPin = yPin;
  this->buttonPin = buttonPin;
  lastDirection = Direction::NONE;
  pinMode(buttonPin, INPUT_PULLUP);
}

float Joystick::map(float x, float inMin, float inMax, float outMin, float outMax)
{
  return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

float Joystick::convertRawValue(int raw, int center, int min, int max)
{
  if (raw > center)
  {
    return map(raw, center, max, 0, 1);
  }
  else
  {
    return map(raw, min, center, -1, 0);
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
  return convertRawValue(getRawX(), X_CENTER, X_MIN, X_MAX);
}

float Joystick::getY()
{
  return convertRawValue(getRawY(), Y_CENTER, Y_MIN, Y_MAX);
}

bool Joystick::isPressed()
{
  // digitalRead returns 0 when pressed, so flip it
  return !digitalRead(buttonPin);
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
  else if (y > 0 && y > fabs(x))
  {
    return Direction::UP;
  }
  else if (y < 0 && -y > fabs(x))
  {
    return Direction::DOWN;
  }
  else if (x < 0 && -x > fabs(y))
  {
    return Direction::LEFT;
  }
  else if (x > 0 && x > fabs(y))
  {
    return Direction::RIGHT;
  }
  else
  {
    return Direction::NONE; // Catch-all case, just in case
  }
}

Direction Joystick::getDirectionDebounced()
{
  Direction direction = getDirection();
  bool wasDirectionJustInputted = direction != lastDirection;
  lastDirection = direction;
  return wasDirectionJustInputted ? direction : NONE;
}
