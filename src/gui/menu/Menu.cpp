#include "Menu.h"
#include "Squidbox.h"

Menu::Menu(const char *name, int numMenuItems, MenuItem **menuItems, SceneType parentScene)
    : name(name), numMenuItems(numMenuItems), menuItems(menuItems), parentScene(parentScene), selectedIndex(0)
{
}

Menu::Menu(const char *name, int numMenuItems, MenuItem **menuItems)
    : Menu(name, numMenuItems, menuItems, NULL_SCENE)
{
}

Menu::Menu(const char *name, SceneType parentScene)
    : Menu(name, 0, nullptr, parentScene)
{
}

void Menu::update(Squidbox *squidbox)
{
  // Handle joystick inputs
  Joystick *joystick = squidbox->getJoystick();

  if (joystick->wasUpJustInputted())
  {
    selectedIndex = getPreviousIndex();
  }
  else if (joystick->wasDownJustInputted())
  {
    selectedIndex = getNextIndex();
  }

  // Handle ok button
  if (hasMenuItems())
  {
    Button *okButton = squidbox->getOkButton();

    if (okButton->isPressed())
    {
      menuItems[selectedIndex]->onSelect();
    }
  }

  // Handle back button
  if (hasParentScene())
  {
    Button *backButton = squidbox->getBackButton();
    if (backButton->isPressed())
    {
      squidbox->switchTo(parentScene);
    }
  }

  // TODO: Handle knob inputs

  Screen *screen = squidbox->getScreen();
  screen->clear();
  screen->getDisplay()->setTextSize(1);
  screen->getDisplay()->setTextColor(WHITE);
  screen->getDisplay()->setCursor(0, 0);

  // TODO: Add a header bar that shows battery, BLE connection, etc.
  // For now just printing an empty line
  screen->getDisplay()->printf("\n");

  if (hasParentScene())
  {
    screen->getDisplay()->write(ASCII_LEFT_ARROW);
  }
  screen->getDisplay()->printf("%s\n", name);

  for (int i = 0; i < numMenuItems; i++)
  {
    MenuItem *menuItem = menuItems[i];
    int prefix = i == selectedIndex ? menuItem->getPrefix() : ASCII_NULL;
    screen->getDisplay()->write(prefix);
    screen->getDisplay()->printf("%s\n", menuItem->getName());
  }

  screen->update();
}

void Menu::setName(const char *name)
{
  this->name = name;
}

bool Menu::hasMenuItems()
{
  return numMenuItems > 0;
}

bool Menu::hasParentScene()
{
  return parentScene != NULL_SCENE;
}

int Menu::getNextIndex()
{
  return min(selectedIndex + 1, numMenuItems - 1);
}

int Menu::getPreviousIndex()
{
  return max(selectedIndex - 1, 0);
}

void Menu::onKnobLeft(int count, void *usr_data)
{
  Menu *self = static_cast<Menu *>(usr_data);

  // Knob triggers twice per click, so we only want to trigger the event every other click
  if (count % 2 == 0)
  {
    self->menuItems[self->selectedIndex]->onKnobLeft();
  }
}

void Menu::onKnobRight(int count, void *usr_data)
{
  Menu *self = static_cast<Menu *>(usr_data);

  // Knob triggers twice per click, so we only want to trigger the event every other click
  if (count % 2 == 0)
  {
    self->menuItems[self->selectedIndex]->onKnobRight();
  }
}