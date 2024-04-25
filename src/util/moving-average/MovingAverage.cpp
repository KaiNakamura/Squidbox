#include "MovingAverage.h"

MovingAverage::MovingAverage(int size) : size(size) {
  // Allocate memory for the window array
  window = new int[size];
}

MovingAverage::~MovingAverage() {
  // Deallocate memory of the window array
  delete[] window;
}

float MovingAverage::next(int val) {
  // Check if the window is full
  if (nextIndex == size) {
    // Subtract the oldest value from the sum
    sum -= window[0];

    // Shift all values in the window to the left
    for (int i = 0; i < size - 1; ++i) {
      window[i] = window[i + 1];
    }

    // Decrease the next index by 1
    nextIndex--;
  }

  // Add the new value to the window
  window[nextIndex++] = val;

  // Increase the sum by the new value
  sum += val;

  // Return the average of the values in the window
  return sum / nextIndex;
}