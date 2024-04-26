#include "JoystickCalibratorScene.h"
#include "Squidbox.h"

JoystickCalibratorScene::JoystickCalibratorScene(Squidbox *squidbox)
    : Scene(squidbox, nullptr) {
  // Create a new menu with the name "Joystick Calibrator" and parent scene as
  // MAIN_SCENE
  menu = new Menu("Joystick Calibrator", MAIN_SCENE);
}

void JoystickCalibratorScene::init() {
  // Call the initialization function of the parent class
  Scene::init();

  // Initialize moving averages for x and y
  xAverage = new MovingAverage(NUM_SAMPLES);
  yAverage = new MovingAverage(NUM_SAMPLES);

  // Initialize minimum and maximum values for x and y
  xMin = 4096;
  yMin = 4096;
  xMax = -1;
  yMax = -1;
}

void JoystickCalibratorScene::update() {
  // Call the update function of the parent class
  Scene::update();

  // Get the joystick
  Joystick *joystick = squidbox->getJoystick();

  // Get the raw x and y values from the joystick
  int rawX = joystick->getRawX();
  int rawY = joystick->getRawY();

  // Update the minimum and maximum x values
  if (rawX < xMin) {
    xMin = rawX;
  } else if (rawX > xMax) {
    xMax = rawX;
  }

  // Update the minimum and maximum y values
  if (rawY < yMin) {
    yMin = rawY;
  } else if (rawY > yMax) {
    yMax = rawY;
  }

  // Calculate the average x and y values
  float averageX = xAverage->next(joystick->getRawX());
  float averageY = yAverage->next(joystick->getRawY());

  // Get the x and y values from the joystick
  float x = joystick->getX();
  float y = joystick->getY();

  // Get the direction from the joystick
  Direction direction = joystick->getDirection();

  // Print the raw, average, and actual x and y values, and the direction
  Serial.printf("raw: (%.0f, %.0f), xRange: [%d, %d], yRange: [%d, %d], (x, "
                "y): (%.2f, %.2f) %s\n",
                averageX, averageY, xMin, xMax, yMin, yMax, x, y,
                directionToString(direction));
}