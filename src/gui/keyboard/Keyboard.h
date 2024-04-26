#pragma once
#include "components/screen/Screen.h"
#include "gui/keyboard/Key.h"
#include "scene/Scene.h"
#include "util/ChordType.h"
#include "util/note/Note.h"
#include "util/scale/Scale.h"
#include <Arduino.h>

/**
 * @class Keyboard
 * @brief A class that represents a musical keyboard to be displayed on the
 * screen.
 */
class Keyboard {
private:
  const static int STARTING_KEY_Y =
      42; ///< The starting Y position for the keys.
  const static int WHITE_KEY_WIDTH = 8;   ///< The width of the white keys.
  const static int WHITE_KEY_HEIGHT = 20; ///< The height of the white keys.
  const static int BLACK_KEY_WIDTH = 5;   ///< The width of the black keys.
  const static int BLACK_KEY_HEIGHT = 12; ///< The height of the black keys.
  const static int NUM_KEYS_TO_DRAW = 24; ///< The number of keys to draw.
  const static int REFRESH_RATE = 20;     ///< The refresh rate in Hz.
  Key **keys;                             ///< The keys of the keyboard.
  Squidbox *squidbox;                     ///< The Squidbox object.
  unsigned long lastUpdate;               ///< The time of the last update.

  /**
   * @brief Check if a key is white based on its root index.
   * @param rootIndex The root index of the key.
   * @return true if the key is white, false otherwise.
   */
  bool isWhiteKey(int rootIndex);

  /**
   * @brief Draws a white key on the keyboard.
   *
   * @param note The musical note associated with the key.
   * @param x The x-coordinate where the key should be drawn.
   */
  void drawWhiteKey(Note note, int x);

  /**
   * @brief Draws a black key on the keyboard.
   *
   * @param note The musical note associated with the key.
   * @param x The x-coordinate where the key should be drawn.
   */
  void drawBlackKey(Note note, int x);

public:
  /**
   * @brief Construct a new Keyboard object.
   * @param squidbox The Squidbox object.
   */
  Keyboard(Squidbox *squidbox); /**
                                 * @brief Update the keyboard.
                                 * @param root The root note of the keyboard.
                                 */
  void update(Note root);

  /**
   * @brief Draw the keyboard.
   * @param root The root note of the keyboard.
   */
  void draw(Note root);

  /**
   * @brief Set a key down state.
   * @param note The note of the key.
   * @param down The new down state.
   */
  void setKeyDown(int note, bool down);

  /**
   * @brief Set a key down state.
   * @param note The note of the key.
   * @param down The new down state.
   */
  void setKeyDown(Note note, bool down);
};