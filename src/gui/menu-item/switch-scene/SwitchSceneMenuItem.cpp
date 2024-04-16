#include "SwitchSceneMenuItem.h"
#include "Squidbox.h"

SwitchSceneMenuItem::SwitchSceneMenuItem(const char *name, Squidbox *squidbox, SceneType targetScene) : MenuItem(name), squidbox(squidbox), targetScene(targetScene)
{
  setOnSelectCallback(onSelect, this);
}

void SwitchSceneMenuItem::onSelect(void *arg)
{
  SwitchSceneMenuItem *self = static_cast<SwitchSceneMenuItem *>(arg);
  self->squidbox->switchTo(self->targetScene);
}
