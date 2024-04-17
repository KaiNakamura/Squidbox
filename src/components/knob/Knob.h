#pragma once

#include <Arduino.h>
#include <ESP_Knob.h>

class Knob {
private:
  int buttonPin;
  ESP_Knob *knob;

public:
  Knob(int aPin, int bPin, int buttonPin);

  /**
   * @brief Returns if the knob is pressed
   *
   * @return bool
   */
  bool isPressed();

  int getCount();

  void clearCount();

  /**
   * @brief Set the user data for all events
   *
   * @param usr_data
   */
  void setEventUserData(void *usr_data);

  /**
   * @brief Attach the knob left callback function
   *
   * @param callback Callback function
   */
  void attachLeftEventCallback(std::function<void(int, void *)> callback);

  /**
   * @brief Detach the knob right callback function
   *
   */
  void detachLeftEventCallback(void);

  /**
   * @brief Attach the knob right callback function
   *
   * @param callback Callback function
   */
  void attachRightEventCallback(std::function<void(int, void *)> callback);

  /**
   * @brief Detach the knob right callback function
   *
   */
  void detachRightEventCallback(void);
};