#include "Menu.h"
#include "Squidbox.h"

Menu::Menu(char *name, int numMenuItems, MenuItem *menuItems)
{
  this->name = name;
  this->numMenuItems = numMenuItems;
  this->menuItems = menuItems;
  selectedIndex = 0;
}

void Menu::update(Squidbox *squidbox)
{
  Joystick *joystick = squidbox->getJoystick();

  if (joystick->wasUpJustInputted())
  {
    selectedIndex = getPreviousIndex();
  }
  else if (joystick->wasDownJustInputted())
  {
    selectedIndex = getNextIndex();
  }

  Screen *screen = squidbox->getScreen();
  screen->clear();
  screen->getDisplay()->setTextSize(2);
  screen->getDisplay()->setTextColor(WHITE);
  screen->getDisplay()->setCursor(0, 0);

  screen->getDisplay()->printf("%s\n", name);

  for (int i = 0; i < numMenuItems; i++)
  {
    int prefix = i == selectedIndex ? ASCII_RIGHT_FAT_ARROW : ASCII_NULL;
    screen->getDisplay()->write(prefix);
    screen->getDisplay()->printf("%s\n", menuItems[i].getName());
  }

  screen->update();
}

int Menu::getNextIndex()
{
  return min(selectedIndex + 1, numMenuItems - 1);
}

int Menu::getPreviousIndex()
{
  return max(selectedIndex - 1, 0);
}