#pragma once

#include "scene/Scene.h"
#include "util/ChordType.h"
#include "util/note/Note.h"
#include "util/scale/Scale.h"

/**
 * @class Key
 * @brief A class that represents a musical key.
 */
class Key {
private:
  bool down;  ///< Indicates whether the key is down.
  bool white; ///< Indicates whether the key is white.
  Note note;  ///< The note associated with the key.

public:
  /**
   * @brief Construct a new Key object.
   * @param note The note associated with the key.
   * @param white Indicates whether the key is white.
   */
  Key(Note note, bool white);

  /**
   * @brief Check if the key is down.
   * @return true if the key is down, false otherwise.
   */
  bool isDown();

  /**
   * @brief Set the key down state.
   * @param down The new down state.
   */
  void setDown(bool down);

  /**
   * @brief Check if the key is white.
   * @return true if the key is white, false otherwise.
   */
  bool isWhite();

  /**
   * @brief Set the key color.
   * @param white The new color state.
   */
  void setWhite(bool white);

  /**
   * @brief Get the note associated with the key.
   * @return The note.
   */
  Note getNote();

  /**
   * @brief Set the note associated with the key.
   * @param note The new note.
   */
  void setNote(Note note);
};