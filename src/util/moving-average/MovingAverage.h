#pragma once

/**
 * @class MovingAverage
 * @brief A class that calculates the moving average of a series of numbers
 */
class MovingAverage {
private:
  int *window;       ///< Pointer to the array of numbers
  int size;          ///< Size of the moving window
  int nextIndex = 0; ///< Index where the next number will be added
  float sum = 0;     ///< Sum of the numbers in the window

public:
  /**
   * @brief Construct a new Moving Average object
   * @param size Size of the moving window
   */
  MovingAverage(int size);

  /**
   * @brief Destroy the Moving Average object
   */
  ~MovingAverage();

  /**
   * @brief Add a new number to the window and calculate the moving average
   * @param val The new number to add
   * @return The moving average of the numbers in the window
   */
  float next(int val);
};