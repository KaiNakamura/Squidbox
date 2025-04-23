#include "Config.h"
#include "LittleFS.h"
#include <Arduino.h>
#include <ArduinoJson.h>

#define FORMAT_FS_IF_FAILED true

Config::Config(const char *configFile) : configFile(configFile) {}

void Config::begin() {
  // NOTE: ignore errors for now
  if (!LittleFS.begin(FORMAT_FS_IF_FAILED)) {
    return;
  }
  loadPresets();
}

const std::vector<Preset> &Config::getPresets() const { return presets; }

ConfigError Config::loadPresets() {
  File file = LittleFS.open(configFile, FILE_READ);
  if (!file) {
    return CONFIG_FILE_NOT_FOUND;
  }

  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, file);
  file.close();

  if (error) {
    return CONFIG_READ_ERROR;
  }

  presets.clear();
  for (JsonObject presetObj : doc["presets"].as<JsonArray>()) {
    Preset preset;
    preset.name = presetObj["name"].as<String>();
    preset.description = presetObj["description"].as<String>();

    JsonArray notesArray = presetObj["notes"].as<JsonArray>();
    for (size_t i = 0; i < preset.notes.size(); i++) {
      preset.notes[i].clear();
      if (i < notesArray.size()) {
        for (int note : notesArray[i].as<JsonArray>()) {
          preset.notes[i].push_back(note);
        }
      }
    }

    presets.push_back(preset);
  }

  return CONFIG_NOERROR;
}

ConfigError Config::setPresets(const std::vector<Preset> &newPresets) {
  presets = newPresets;

  File file = LittleFS.open(configFile, FILE_WRITE);
  if (!file) {
    return CONFIG_FILE_NOT_FOUND;
  }

  JsonDocument doc;
  JsonArray presetsArray = doc["presets"].to<JsonArray>();

  for (const Preset &preset : presets) {
    JsonObject presetObj = presetsArray.add<JsonObject>();
    presetObj["name"] = preset.name;
    presetObj["description"] = preset.description;

    JsonArray notesArray = presetObj["notes"].to<JsonArray>();
    for (const auto &notes : preset.notes) {
      JsonArray noteArray = notesArray.add<JsonArray>();
      for (int note : notes) {
        noteArray.add(note);
      }
    }
  }

  ConfigError ret;
  if (serializeJson(doc, file) == 0) {
    ret = CONFIG_WRITE_ERROR;
  } else {
    ret = CONFIG_NOERROR;
  }

  file.close();
  return ret;
}