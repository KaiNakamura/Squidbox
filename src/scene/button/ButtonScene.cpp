#include "ButtonScene.h"
#include "Squidbox.h"

ButtonScene::ButtonScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  // Create a new menu with the name "Button" and parent scene as MAIN_SCENE
  menu = new Menu("Button", MAIN_SCENE);
}

void ButtonScene::update() {
  // Call the update function of the parent class
  Scene::update();

  // Loop through all the buttons
  for (int i = 0; i < Squidbox::NUM_BUTTONS; i++) {
    // Get the current button
    Button *button = squidbox->getButton(i);

    // Check if the button is pressed
    if (button->isPressed()) {
      // If the button is pressed, print a message to the serial monitor
      Serial.printf("Button %d was pressed\n", i);
    }

    // Check if the button is released
    if (button->isReleased()) {
      // If the button is released, print a message to the serial monitor
      Serial.printf("Button %d was released\n", i);
    }
  }
}