#include "PresetMenuItem.h"

PresetMenuItem::PresetMenuItem() : MenuItem(), presetIndex(0) {
    this->presets = presets;
    
    // Set the callbacks for when the knob is turned left or right
    setOnKnobLeftCallback(onKnobLeft, this);
    setOnKnobRightCallback(onKnobRight, this);

    // Update the name of the menu item to reflect the current preset
    updateName();
}

void PresetMenuItem::updateName() {
    // Set the name of the menu item to the name of the current preset
    setName(getPreset()->name.c_str());
}

void PresetMenuItem::onKnobLeft(void *arg) {
    // Cast the argument to a PresetMenuItem pointer
    PresetMenuItem *self = static_cast<PresetMenuItem *>(arg);

    // Decrease the preset index, but don't let it go below 0
    self->presetIndex = max(self->presetIndex - 1, 0);

    // Update the name of the menu item to reflect the new preset
    self->updateName();
}

void PresetMenuItem::onKnobRight(void *arg) {
    // Cast the argument to a PresetMenuItem pointer
    PresetMenuItem *self = static_cast<PresetMenuItem *>(arg);

    // Increase the preset index, but don't let it go above the number of presets
    // minus 1
    self->presetIndex = min(self->presetIndex + 1, static_cast<int>(Config::getPresets().size()) - 1);

    // Update the name of the menu item to reflect the new preset
    self->updateName();
}

const Preset *PresetMenuItem::getPreset() {
    // Return the preset at the current index
    return &Config::getPresets().at(presetIndex);
}
