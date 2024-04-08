#include "MenuItem.h"

MenuItem::MenuItem(char *name)
{
  this->name = name;
}

char *MenuItem::getName()
{
  return name;
}