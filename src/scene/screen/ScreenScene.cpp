#include "ScreenScene.h"
#include "Squidbox.h"

ScreenScene::ScreenScene(Squidbox *squidbox)
{
  type = SCREEN_SCENE;
  this->squidbox = squidbox;
}

void ScreenScene::init()
{
  Serial.println("ScreenScene init");
}

void ScreenScene::update()
{
  Screen *screen = squidbox->getScreen();
  screen->clear();

  screen->setTextSize(1);      // Normal 1:1 pixel scale
  screen->setTextColor(WHITE); // Draw white text
  screen->setCursor(0, 0);     // Start at top-left corner

  // Not all the characters will fit on the screen
  // It will draw what it can and the rest will be clipped.
  for (int16_t i = 0; i < 256; i++)
  {
    if (i == '\n')
    {
      screen->write(' ');
    }
    else
    {
      screen->write(i);
    }
  }

  screen->update();
}