#pragma once

class MovingAverage
{
private:
  int *window;
  int size;
  int nextIndex = 0;
  float sum = 0;

public:
  MovingAverage(int size);
  ~MovingAverage();
  float next(int val);
};