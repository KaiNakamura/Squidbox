#pragma once

#include "Squidbox.h"
#include "gui/menu-item/MenuItem.h"

/**
 * @class QuitMenuItem
 * @brief A class that represents a menu item for putting the device in sleep
 * mode.
 * @details This class is a subclass of MenuItem and adds functionality for
 * putting the device in sleep mode.
 */
class QuitMenuItem : public MenuItem {
private:
  Squidbox *squidbox; ///< The Squidbox object.

  /**
   * @brief Handle the select event.
   * @param arg The argument passed to the event handler.
   */
  static void onSelect(void *arg);

public:
  /**
   * @brief Construct a new QuitMenuItem object.
   * @param squidbox The Squidbox object.
   */
  QuitMenuItem(Squidbox *squidbox);
};