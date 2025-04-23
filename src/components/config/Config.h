#pragma once

#include <Arduino.h>
#include <vector>

#define MAX_BUTTONS 8

struct Preset {
  String name;
  String description;
  std::array<std::vector<int>, MAX_BUTTONS> notes;
};

enum ConfigError {
  CONFIG_NOERROR,
  CONFIG_FILE_NOT_FOUND,
  CONFIG_READ_ERROR,
  CONFIG_WRITE_ERROR,
};

class Config {
private:
  std::vector<Preset> presets;
  const char *configFile;

public:
  Config(const char *configFile);

  // Called on startup to load presets from the current config file
  void begin();

  const std::vector<Preset> &getPresets() const;
  // Reads the presets from the config file and updates the in-memory config
  ConfigError loadPresets();
  // Persists the current presets to the in-memory config and the config file
  ConfigError setPresets(const std::vector<Preset> &presets);
};