#include "MovingAverage.h"

MovingAverage::MovingAverage(int size) : size(size) { window = new int[size]; }

MovingAverage::~MovingAverage() { delete[] window; }

float MovingAverage::next(int val) {
  if (nextIndex == size) {
    sum -= window[0];
    for (int i = 0; i < size - 1; ++i) {
      window[i] = window[i + 1];
    }
    nextIndex--;
  }
  window[nextIndex++] = val;
  sum += val;
  return sum / nextIndex;
}