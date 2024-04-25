#include "Knob.h"

Knob::Knob(int aPin, int bPin, int buttonPin) : buttonPin(buttonPin) {
  // Set the button pin as an input with a pull-up resistor.
  pinMode(buttonPin, INPUT_PULLUP);
  // Create a new ESP_Knob object with the given aPin and bPin.
  knob = new ESP_Knob(aPin, bPin);
  // Initialize the ESP_Knob object.
  knob->begin();
}

bool Knob::isPressed() {
  // Read the digital value from the buttonPin and return it.
  // Note: This function is currently not working due to a wiring issue.
  return digitalRead(buttonPin);
}

int Knob::getCount() {
  // Return the count value from the ESP_Knob object.
  // Note: The count value on the ESP_Knob increases by 2 for every click.
  return knob->getCountValue();
}

void Knob::clearCount() {
  // Clear the count value in the ESP_Knob object.
  knob->clearCountValue();
}

void Knob::setEventUserData(void *usr_data) {
  // Set the user data for events in the ESP_Knob object.
  // Note: The ESP_Knob library misspelled "Data" as "Date".
  knob->setEventUserDate(usr_data);
}

void Knob::attachLeftEventCallback(std::function<void(int, void *)> callback) {
  // Attach the given callback function to the left event in the ESP_Knob
  // object.
  knob->attachLeftEventCallback(callback);
}

void Knob::detachLeftEventCallback(void) {
  // Detach the callback function from the left event in the ESP_Knob object.
  knob->detachLeftEventCallback();
}

void Knob::attachRightEventCallback(std::function<void(int, void *)> callback) {
  // Attach the given callback function to the right event in the ESP_Knob
  // object.
  knob->attachRightEventCallback(callback);
}

void Knob::detachRightEventCallback(void) {
  // Detach the callback function from the right event in the ESP_Knob object.
  knob->detachRightEventCallback();
}