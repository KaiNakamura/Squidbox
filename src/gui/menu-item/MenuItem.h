#pragma once

#include "util/Ascii.h"
#include <functional>

class Scene;

/**
 * @class MenuItem
 * @brief A class that represents an individual selectable option within a Menu.
 * @details The MenuItem class is a fundamental component of the user interface,
 * representing a single selectable option within a Menu. Each MenuItem can be
 * associated with a specific action or behavior, which is triggered when the
 * item is selected by the user. This allows for a modular design where each
 * MenuItem encapsulates a specific functionality, contributing to the overall
 * interactivity of the Menu within a Scene.
 */
class MenuItem {
public:
  using CallbackFunction =
      std::function<void(void *)>; ///< Type definition for callback functions.

  /**
   * @brief Construct a new MenuItem object with a given name.
   * @param name The name of the menu item.
   */
  MenuItem(const char *name);

  /**
   * @brief Construct a new MenuItem object.
   */
  MenuItem();

  /**
   * @brief Get the name of the menu item.
   * @return The name of the menu item.
   */
  const char *getName();

  /**
   * @brief Set the name of the menu item.
   * @param name The new name of the menu item.
   */
  void setName(const char *name);

  /**
   * @brief Set the callback function to be called when the menu item is
   * selected.
   * @param cb The callback function.
   * @param arg The argument to be passed to the callback function.
   */
  void setOnSelectCallback(CallbackFunction cb, void *arg = nullptr);

  /**
   * @brief Set the callback function to be called when the left knob is turned.
   * @param cb The callback function.
   * @param arg The argument to be passed to the callback function.
   */
  void setOnKnobLeftCallback(CallbackFunction cb, void *arg = nullptr);

  /**
   * @brief Set the callback function to be called when the right knob is
   * turned.
   * @param cb The callback function.
   * @param arg The argument to be passed to the callback function.
   */
  void setOnKnobRightCallback(CallbackFunction cb, void *arg = nullptr);

  /**
   * @brief Call the select callback function.
   */
  void onSelect();

  /**
   * @brief Call the left knob callback function.
   */
  void onKnobLeft();

  /**
   * @brief Call the right knob callback function.
   */
  void onKnobRight();

  /**
   * @brief Get the prefix of the menu item.
   * @return The prefix of the menu item.
   */
  Ascii getPrefix();

private:
  const char *name; ///< The name of the menu item.
  Scene *scene;     ///< The scene associated with the menu item.
  CallbackFunction selectCallback, knobLeftCallback,
      knobRightCallback; ///< The callback functions.
  void *selectArg, *knobLeftArg,
      *knobRightArg; ///< The arguments for the callback functions.
};