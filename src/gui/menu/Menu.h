#pragma once

#include "gui/menu-item/MenuItem.h"

class Squidbox;

class Menu
{
private:
  char *name;
  int numMenuItems;
  int selectedIndex;
  MenuItem *menuItems;
  int getNextIndex();
  int getPreviousIndex();

public:
  Menu(char *name, int numMenuItems, MenuItem *menuItems);
  void update(Squidbox *squidbox);
};