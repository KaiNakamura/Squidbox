#include "SwitchSceneMenuItem.h"
#include "Squidbox.h"

SwitchSceneMenuItem::SwitchSceneMenuItem(const char *name, Squidbox *squidbox,
                                         SceneType targetScene)
    : MenuItem(name), squidbox(squidbox), targetScene(targetScene) {
  // Set the callback for when the menu item is selected
  setOnSelectCallback(onSelect, this);
}

void SwitchSceneMenuItem::onSelect(void *arg) {
  // Cast the argument to a SwitchSceneMenuItem pointer
  SwitchSceneMenuItem *self = static_cast<SwitchSceneMenuItem *>(arg);

  // Call the switchTo method on the Squidbox instance with the target scene
  // This will switch the current scene to the target scene
  self->squidbox->switchTo(self->targetScene);
}