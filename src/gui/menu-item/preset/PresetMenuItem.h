#pragma once

#include "gui/menu-item/MenuItem.h"
#include "util/scale/Scale.h"
#include <components/config/Config.h>

/**
 * @class PresetMenuItem
 * @brief A class that represents a menu item for presets. 
 * @details This class is a subclass of MenuItem and adds functionality for
 * handling presets.
 */
class PresetMenuItem : public MenuItem {
private:
  std::vector<Preset>* presets; ///< A pointer to the vector of presets.
  
  int presetIndex; ///< The index of the preset.

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
   * @brief Update the name of the menu item based on the current preset.
   */
  void updateName();

public:
  /**
   * @brief Construct a new PresetMenuItem object.
   */
  PresetMenuItem();

  /**
   * @brief Get the current preset.
   * @return The current preset.
   */
  const Preset *getPreset();
};
