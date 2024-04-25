#pragma once

#include "gui/menu-item/quit/QuitMenuItem.h"
#include "gui/menu-item/switch-scene/SwitchSceneMenuItem.h"
#include "gui/menu/Menu.h"
#include "scene/Scene.h"
#include "util/Ascii.h"

/**
 * @class MainScene
 * @brief A class that represents the main scene of the Squidbox device.
 * @details This class is a subclass of Scene and represents the primary state
 * of the Squidbox device. It provides the main user interface and
 * functionality, serving as the central hub from which other scenes can be
 * accessed.
 */
class MainScene : public Scene {
public:
  /**
   * @brief Construct a new MainScene object.
   * @param squidbox The Squidbox object.
   */
  MainScene(Squidbox *squidbox);
};