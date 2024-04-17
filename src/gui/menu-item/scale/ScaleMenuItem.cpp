#include "ScaleMenuItem.h"

ScaleMenuItem::ScaleMenuItem() : MenuItem(), scaleIndex(0)
{
  setOnKnobLeftCallback(onKnobLeft, this);
  setOnKnobRightCallback(onKnobRight, this);
  updateName();
}

void ScaleMenuItem::updateName()
{
  setName(getScale()->getName());
}

void ScaleMenuItem::onKnobLeft(void *arg)
{
  ScaleMenuItem *self = static_cast<ScaleMenuItem *>(arg);
  self->scaleIndex = max(self->scaleIndex - 1, 0);
  self->updateName();
}

void ScaleMenuItem::onKnobRight(void *arg)
{
  ScaleMenuItem *self = static_cast<ScaleMenuItem *>(arg);
  self->scaleIndex = min(self->scaleIndex + 1, Scale::NUM_SCALES - 1);
  self->updateName();
}

Scale *ScaleMenuItem::getScale()
{
  return Scale::SCALES[scaleIndex];
}