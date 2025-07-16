#pragma once

#include <Arduino.h>
#include <vector>
#include <util/preset/Preset.h>

#define CONFIG_FILE "/config.json"

enum ConfigError {
  CONFIG_NOERROR,
  CONFIG_FILE_NOT_FOUND,
  CONFIG_READ_ERROR,
  CONFIG_WRITE_ERROR,
};

class Config {
private:
  static std::vector<Preset> presets;
  static const char *configFile;

public:
  // Initializes the static configFile path
  static void init(const char *filePath);

  // Called on startup to load presets from the current config file
  static void begin();

  // Get current presets
  static const std::vector<Preset>& getPresets();

  // Reads the presets from the config file and updates the in-memory config
  static ConfigError loadPresets();

  // Persists the current presets to the in-memory config and the config file
  static ConfigError writePresets(const std::vector<Preset> &newPresets);
};