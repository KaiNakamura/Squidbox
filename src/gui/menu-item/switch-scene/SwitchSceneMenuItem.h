#pragma once

#include "gui/menu-item/MenuItem.h"
#include "scene/Scene.h"

/**
 * @class SwitchSceneMenuItem
 * @brief A class that represents a menu item for switching scenes.
 * @details This class is a subclass of MenuItem and adds functionality for
 * switching scenes.
 */
class SwitchSceneMenuItem : public MenuItem {
private:
  Squidbox *squidbox;    ///< The Squidbox object.
  SceneType targetScene; ///< The target scene to switch to.

  /**
   * @brief Handle the select event.
   * @param arg The argument passed to the event handler.
   */
  static void onSelect(void *arg);

public:
  /**
   * @brief Construct a new SwitchSceneMenuItem object.
   * @param name The name of the menu item.
   * @param squidbox The Squidbox object.
   * @param targetScene The target scene to switch to.
   */
  SwitchSceneMenuItem(const char *name, Squidbox *squidbox,
                      SceneType targetScene);
};