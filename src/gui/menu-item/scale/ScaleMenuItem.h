#pragma once

#include "gui/menu-item/MenuItem.h"
#include "util/scale/Scale.h"

/**
 * @class ScaleMenuItem
 * @brief A class that represents a menu item for scales.
 * @details This class is a subclass of MenuItem and adds functionality for
 * handling scales.
 */
class ScaleMenuItem : public MenuItem {
private:
  int scaleIndex; ///< The index of the scale.

  /**
   * @brief Handle the left knob event.
   * @param arg The argument passed to the event handler.
   */
  static void onKnobLeft(void *arg);

  /**
   * @brief Handle the right knob event.
   * @param arg The argument passed to the event handler.
   */
  static void onKnobRight(void *arg);

  /**
   * @brief Update the name of the menu item based on the current scale.
   */
  void updateName();

public:
  /**
   * @brief Construct a new ScaleMenuItem object.
   */
  ScaleMenuItem();

  /**
   * @brief Get the current scale.
   * @return The current scale.
   */
  Scale *getScale();
};