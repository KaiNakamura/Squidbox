#pragma once

#include "gui/menu-item/MenuItem.h"
#include "util/ChordType.h"
#include <Arduino.h>

/**
 * @class ChordTypeMenuItem
 * @brief A class that represents a menu item for chord types.
 * @details This class is a subclass of MenuItem and adds functionality for
 * handling chord types.
 */
class ChordTypeMenuItem : public MenuItem {
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
   * @brief Update the name of the menu item based on the current chord type.
   */
  void updateName();

  int chordTypeIndex; ///< The index of the chord type.

public:
  /**
   * @brief Construct a new ChordTypeMenuItem object.
   */
  ChordTypeMenuItem();

  /**
   * @brief Get the current chord type.
   * @return The current chord type.
   */
  ChordType *getChordType();
};