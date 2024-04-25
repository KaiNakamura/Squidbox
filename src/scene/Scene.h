#pragma once

#include "SceneType.h"

class Squidbox;
class Menu;

/**
 * @class Scene
 * @brief A class that represents a discrete state of the Squidbox device.
 * @details In the context of the Squidbox, a scene is a distinct state that
 * provides specific functionality. Each scene encapsulates a unique aspect of
 * the Squidbox's operation, allowing for a modular design where different
 * scenes can offer different user experiences. This could include different
 * modes of operation, different user interfaces, or different sets of features.
 */
class Scene {
protected:
  Squidbox *squidbox; ///< The Squidbox object.
  Menu *menu;         ///< The Menu object.

public:
  /**
   * @brief Construct a new Scene object.
   * @param squidbox The Squidbox object.
   * @param menu The Menu object.
   */
  Scene(Squidbox *squidbox, Menu *menu);

  /**
   * @brief Get the Squidbox object.
   * @return The Squidbox object.
   */
  Squidbox *getSquidbox();

  /**
   * @brief Initialize the scene.
   * @details This is a virtual function that can be overridden by subclasses.
   */
  virtual void init();

  /**
   * @brief Update the scene.
   * @details This is a virtual function that can be overridden by subclasses.
   */
  virtual void update();
};