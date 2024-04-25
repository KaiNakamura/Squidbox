#include "KnobScene.h"
#include "Squidbox.h"

KnobScene::KnobScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  // Create a new menu with the name "Knob" and parent scene as MAIN_SCENE
  menu = new Menu("Knob", MAIN_SCENE);
}

void KnobScene::init() {
  // Call the initialization function of the parent class
  Scene::init();

  // Get the knob from the squidbox
  Knob *knob = squidbox->getKnob();

  // Attach the left and right event callbacks to the knob
  knob->attachLeftEventCallback(leftCallback);
  knob->attachRightEventCallback(rightCallback);

  // Set the user data for the knob events to this instance of KnobScene
  knob->setEventUserData(this);
}

void KnobScene::leftCallback(int count, void *usr_data) {
  // Cast the user data to a KnobScene instance
  KnobScene *self = static_cast<KnobScene *>(usr_data);

  // Get the count from the knob in the squidbox
  int squidboxCount = self->squidbox->getKnob()->getCount();

  // Print a message indicating a left event was detected
  Serial.printf("Detect left event, count is %d, squidbox count is %d\n", count,
                squidboxCount);
}

void KnobScene::rightCallback(int count, void *usr_data) {
  // Cast the user data to a KnobScene instance
  KnobScene *self = static_cast<KnobScene *>(usr_data);

  // Get the count from the knob in the squidbox
  int squidboxCount = self->squidbox->getKnob()->getCount();

  // Print a message indicating a right event was detected
  Serial.printf("Detect right event, count is %d, squidbox count is %d\n",
                count, squidboxCount);
}