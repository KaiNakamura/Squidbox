#pragma once

#include "scene/Scene.h"
#include "util/moving-average/MovingAverage.h"

/**
 * @class JoystickCalibratorScene
 * @brief A class that represents a test scene for calibrating the joystick.
 * @details This class is a subclass of Scene and is specifically designed for
 * testing and calibrating the joystick component of the Squidbox device. It
 * uses a moving average to smooth out the joystick readings. Note that this is
 * a test scene and is not intended to be accessed by a user during normal
 * operation of the device.
 */
class JoystickCalibratorScene : public Scene {
private:
  const int NUM_SAMPLES =
      200; ///< The number of samples to use for the moving average.
  MovingAverage *xAverage, *yAverage; ///< The moving averages for the x and y
                                      ///< coordinates of the joystick.
  int xMin, yMin, xMax, yMax; ///< The minimum and maximum values for the x and
                              ///< y coordinates of the joystick.

public:
  /**
   * @brief Construct a new JoystickCalibratorScene object.
   * @param squidbox The Squidbox object.
   */
  JoystickCalibratorScene(Squidbox *squidbox);

  /**
   * @brief Initialize the joystick calibrator scene.
   */
  void init() override;

  /**
   * @brief Update the joystick calibrator scene.
   */
  void update() override;
};
