#include "QuitMenuItem.h"

QuitMenuItem::QuitMenuItem(Squidbox *squidbox)
    : MenuItem("Quit"), squidbox(squidbox) {
  setOnSelectCallback(onSelect, this);
}

void QuitMenuItem::onSelect(void *arg) {
  QuitMenuItem *self = static_cast<QuitMenuItem *>(arg);
  self->squidbox->sleep();
}
