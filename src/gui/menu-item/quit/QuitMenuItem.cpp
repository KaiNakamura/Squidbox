#include "QuitMenuItem.h"

QuitMenuItem::QuitMenuItem(Squidbox *squidbox)
    : MenuItem("Quit"), squidbox(squidbox) {
  // Set the callback for when the menu item is selected
  setOnSelectCallback(onSelect, this);
}

void QuitMenuItem::onSelect(void *arg) {
  // Cast the argument to a QuitMenuItem pointer
  QuitMenuItem *self = static_cast<QuitMenuItem *>(arg);

  // Call the sleep method on the Squidbox instance
  // This will put the Squidbox into a low-power state
  self->squidbox->sleep();
}