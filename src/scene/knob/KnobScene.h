#pragma once

#include "components/knob/Knob.h"
#include "scene/Scene.h"

/**
 * @class KnobScene
 * @brief A class that represents a test scene for interacting with the knob
 * component.
 * @details This class is a subclass of Scene and is specifically designed for
 * testing the functionality of the knob component of the Squidbox device. It
 * provides callback functions for left and right knob turns. Note that this is
 * a test scene and is not intended to be accessed by a user during normal
 * operation of the device.
 */
class KnobScene : public Scene {
private:
  /**
   * @brief Callback function for left knob turns.
   * @param count The number of knob turns.
   * @param usr_data User data.
   */
  static void leftCallback(int count, void *usr_data);

  /**
   * @brief Callback function for right knob turns.
   * @param count The number of knob turns.
   * @param usr_data User data.
   */
  static void rightCallback(int count, void *usr_data);

public:
  /**
   * @brief Construct a new KnobScene object.
   * @param squidbox The Squidbox object.
   */
  KnobScene(Squidbox *squidbox);

  /**
   * @brief Initialize the knob scene.
   */
  void init() override;
};