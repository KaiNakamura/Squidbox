#pragma once

#include "gui/menu-item/MenuItem.h"
#include "scene/SceneType.h"

class Squidbox;

class Menu {
private:
  const char *name;
  int numMenuItems;
  int selectedIndex;
  SceneType parentScene;
  MenuItem **menuItems;
  int getNextIndex();
  int getPreviousIndex();

public:
  Menu(const char *name, int numMenuItems, MenuItem **menuItems,
       SceneType parentScene);
  Menu(const char *name, int numMenuItems, MenuItem **menuItems);
  Menu(const char *name, SceneType parentScene);
  void drawMenu(Squidbox *squidbox);
  bool hasMenuItems();
  bool hasParentScene();
  void setName(const char *name);
  static void onKnobLeft(int count, void *usr_data);
  static void onKnobRight(int count, void *usr_data);
};