#pragma once

class MenuItem
{
private:
  char *name;

public:
  MenuItem(char *name);
  char *getName();
};