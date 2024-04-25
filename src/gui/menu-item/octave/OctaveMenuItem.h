#pragma once

#include "gui/menu-item/MenuItem.h"
#include "util/note/Note.h"
#include <Arduino.h>

/**
 * @class OctaveMenuItem
 * @brief A class that represents a menu item for octaves.
 * @details This class is a subclass of MenuItem and adds functionality for
 * handling octaves.
 */
class OctaveMenuItem : public MenuItem {
private:
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
   * @brief Update the name of the menu item based on the current octave.
   */
  void updateName();

  int octaveIndex; ///< The index of the octave.

public:
  /**
   * @brief Construct a new OctaveMenuItem object.
   */
  OctaveMenuItem();

  /**
   * @brief Get the current note.
   * @return The current note.
   */
  Note getNote();
};