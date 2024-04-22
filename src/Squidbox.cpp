#include "Squidbox.h"

Squidbox::Squidbox() {
  // Initialize MIDI server
  BLEMidiServer.begin(getName());

  // Initialize components
  screen = new Screen();
  joystick = new Joystick(PIN_JOYSTICK_X, PIN_JOYSTICK_Y, PIN_JOYSTICK_BUTTON);
  knob = new Knob(PIN_KNOB_A, PIN_KNOB_B, PIN_KNOB_BUTTON);
  backButton = new Button(PIN_BACK_BUTTON);
  okButton = new Button(PIN_OK_BUTTON);
  buttons[0] = new Button(PIN_BUTTON_0);
  buttons[1] = new Button(PIN_BUTTON_1);
  buttons[2] = new Button(PIN_BUTTON_2);
  buttons[3] = new Button(PIN_BUTTON_3);
  buttons[4] = new Button(PIN_BUTTON_4);
  buttons[5] = new Button(PIN_BUTTON_5);
  buttons[6] = new Button(PIN_BUTTON_6);
  buttons[7] = new Button(PIN_BUTTON_7);
}

void Squidbox::init() {
  // Initialize scenes
  scenes[MAIN_SCENE] = new MainScene(this);
  scenes[CHORD_SCENE] = new ChordScene(this);
  scenes[NOTE_SCENE] = new NoteScene(this);
  scenes[JOYSTICK_CALIBRATOR_SCENE] = new JoystickCalibratorScene(this);
  scenes[KNOB_SCENE] = new KnobScene(this);
  scenes[BUTTON_SCENE] = new ButtonScene(this);
}

void Squidbox::update() {
  // If current scene has not been initialized, initialize it
  if (!currentSceneInitialized) {
    scenes[currentScene]->init();
    currentSceneInitialized = true;
  }

  // Update current scene
  scenes[currentScene]->update();
}

void Squidbox::switchTo(SceneType scene) {
  // If the scene has changed, set the new scene and mark it as not initialized
  if (scene != currentScene) {
    currentScene = scene;
    currentSceneInitialized = false;
  }
}

Screen *Squidbox::getScreen() { return screen; }

Joystick *Squidbox::getJoystick() { return joystick; }

Knob *Squidbox::getKnob() { return knob; }

Button *Squidbox::getBackButton() { return backButton; }

Button *Squidbox::getOkButton() { return okButton; }

Button **Squidbox::getButtons() { return buttons; }

Button *Squidbox::getButton(int index) {
  // Check if the index is out of bounds
  if (index < 0 || index > NUM_BUTTONS - 1) {
    Serial.printf("Error: Button not found with index %d\n", index);
  }
  return buttons[index];
}

const char *Squidbox::getDeviceId() {
  // Length of device ID is 17 characters (e.g. "00:00:00:00:00:00")
  static char deviceId[18];
  uint8_t baseMac[6];
  esp_efuse_mac_get_default(baseMac);

  // Only return the last 3 bytes of the MAC address since the first 3 bytes are
  // the manufacturer ID
  sprintf(deviceId, "%02X:%02X:%02X", baseMac[3], baseMac[4], baseMac[5]);
  return deviceId;
}

const char *Squidbox::getName() {
  // Length of "Squidbox " (9 characters) + length of device ID (17 characters)
  static char name[26];
  const char *deviceId = getDeviceId();
  sprintf(name, "Squidbox %s", deviceId);
  return name;
}