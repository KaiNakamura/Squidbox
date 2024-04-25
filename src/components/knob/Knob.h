#pragma once

#include <Arduino.h>
#include <ESP_Knob.h>

/**
 * @class Knob
 * @brief A class that represents a knob.
 */
class Knob {
private:
  int buttonPin;  ///< The GPIO pin the knob button is connected to.
  ESP_Knob *knob; ///< Pointer to the ESP_Knob object.

public:
  /**
   * @brief Construct a new Knob object.
   * @param aPin The A pin for the knob.
   * @param bPin The B pin for the knob.
   * @param buttonPin The button pin for the knob.
   */
  Knob(int aPin, int bPin, int buttonPin);
  /**
   * @brief Returns if the knob is pressed
   * @return bool
   */
  bool isPressed();

  /**
   * @brief Get the count of knob turns
   * @return int
   */
  int getCount();

  /**
   * @brief Clear the count of knob turns
   */
  void clearCount();

  /**
   * @brief Set the user data for all events
   * @param usr_data User data to be set
   */
  void setEventUserData(void *usr_data);

  /**
   * @brief Attach the knob left callback function
   * @param callback Callback function to be attached
   */
  void attachLeftEventCallback(std::function<void(int, void *)> callback);

  /**
   * @brief Detach the knob left callback function
   */
  void detachLeftEventCallback(void);

  /**
   * @brief Attach the knob right callback function
   * @param callback Callback function to be attached
   */
  void attachRightEventCallback(std::function<void(int, void *)> callback);

  /**
   * @brief Detach the knob right callback function
   */
  void detachRightEventCallback(void);
};