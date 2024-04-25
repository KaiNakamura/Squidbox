#pragma once

#include "scene/Scene.h"

/**
 * @class ButtonScene
 * @brief A class that represents a test scene for interacting with the button
 * components.
 * @details This class is a subclass of Scene and is specifically designed for
 * testing the functionality of the button components of the Squidbox device.
 * Note that this is a test scene and is not intended to be accessed by a user
 * during normal operation of the device.
 */
class ButtonScene : public Scene {
public:
  /**
   * @brief Construct a new ButtonScene object.
   * @param squidbox The Squidbox object.
   */
  ButtonScene(Squidbox *squidbox);

  /**
   * @brief Update the button scene.
   */
  void update() override;
};