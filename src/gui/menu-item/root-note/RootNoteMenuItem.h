#pragma once

#include "gui/menu-item/MenuItem.h"
#include "util/note/Note.h"

/**
 * @class RootNoteMenuItem
 * @brief A class that represents a menu item for root notes.
 * @details This class is a subclass of MenuItem and adds functionality for
 * handling root notes.
 */
class RootNoteMenuItem : public MenuItem {
private:
  static const Note MIN_NOTE = NOTE_C1;   ///< The minimum note.
  static const Note MAX_NOTE = NOTE_C7;   ///< The maximum note.
  static const Note START_NOTE = NOTE_C4; ///< The start note.

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
   * @brief Update the name of the menu item based on the current root note.
   */
  void updateName();

  Note root; ///< The root note.

public:
  /**
   * @brief Construct a new RootNoteMenuItem object.
   */
  RootNoteMenuItem();

  /**
   * @brief Get the current root note.
   * @return The current root note.
   */
  Note getRootNote();
};