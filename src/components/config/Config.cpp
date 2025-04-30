#include "Config.h"
#include "LittleFS.h"
#include <ArduinoJson.h>

#define FORMAT_FS_IF_FAILED true

std::vector<Preset> Config::presets;

void Config::begin() {
  if (!LittleFS.begin(FORMAT_FS_IF_FAILED)) {
    Serial.println("Failed to mount LittleFS");
    return;
  }

  loadPresets();
}

const std::vector<Preset>& Config::getPresets() {
  return presets;
}

ConfigError Config::loadPresets() {
  if (!CONFIG_FILE) {
    Serial.println("Config file path not set");
    return CONFIG_FILE_NOT_FOUND;
  }

  File file = LittleFS.open(CONFIG_FILE, FILE_READ);
  if (!file) {
    Serial.println("Failed to open config file");
    return CONFIG_FILE_NOT_FOUND;
  }

  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, file);
  file.close();

  if (error) {
    Serial.println("Failed to parse config file");
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

  Serial.println("Loaded presets:");
  for (const Preset &preset : presets) {
    Serial.print("  ");
    Serial.print(preset.name);
    Serial.print(": ");
    Serial.println(preset.description);
  }

  return CONFIG_NOERROR;
}

ConfigError Config::writePresets(const std::vector<Preset> &newPresets) {
  if (!CONFIG_FILE) {
    Serial.println("Config file path not set");
    return CONFIG_FILE_NOT_FOUND;
  }

  presets = newPresets;

  File file = LittleFS.open(CONFIG_FILE, FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open config file");
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
    Serial.println("Failed to write config file");
    ret = CONFIG_WRITE_ERROR;
  } else {
    Serial.println("Config file written successfully");
    ret = CONFIG_NOERROR;
  }

  file.close();
  return ret;
}
