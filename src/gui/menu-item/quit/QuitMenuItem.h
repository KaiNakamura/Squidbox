#pragma once

#include "Squidbox.h"
#include "gui/menu-item/MenuItem.h"

class QuitMenuItem : public MenuItem {
private:
  Squidbox *squidbox;
  static void onSelect(void *arg);

public:
  QuitMenuItem(Squidbox *squidbox);
};