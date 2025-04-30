#include "Commander.h"
#include <ArduinoJson.h>


void cmd_unrecognized(SerialCommands *sender, const char *cmd) {
  sender->GetSerial()->print("\nERR Unrecognized command [");
  sender->GetSerial()->print(cmd);
  sender->GetSerial()->println("]");
}

// GETCONF
// Respond with OK <json string> or ERR <error string>
void Commander::cmd_getconf(SerialCommands *sender) {

  const std::vector<Preset> &presets = Config::getPresets();
  JsonDocument doc;

  JsonArray presetsArray = doc["presets"].to<JsonArray>();
  for (const Preset &preset : presets) {
    JsonObject presetObj = presetsArray.add<JsonObject>();
    presetObj["name"] = preset.name;
    presetObj["description"] = preset.description;

    JsonArray notesArray = presetObj["notes"].to<JsonArray>();
    for (const auto &notes : preset.notes) {
      JsonArray noteArray = notesArray.add<JsonArray>(); // Updated here
      for (int note : notes) {
        noteArray.add(note);
      }
    }
  }

  String jsonString;
  serializeJson(doc, jsonString);
  sender->GetSerial()->print("OK ");
  sender->GetSerial()->println(jsonString);
}

// SETCONF <json string>
// Respond with OK or ERR <error string>
void Commander::cmd_setconf(SerialCommands *sender) {
  char *jsonString = sender->Next();
  
  if (!jsonString) {
    sender->GetSerial()->println("ERR Missing JSON string");
    return;
  }

  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, jsonString);

  if (error) {
    sender->GetSerial()->print("ERR Failed to parse JSON: ");
    sender->GetSerial()->println(error.c_str());
    return;
  }

  std::vector<Preset> newPresets;
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

    newPresets.push_back(preset);
  }

  switch (Config::writePresets(newPresets)) {
    case CONFIG_NOERROR:
      sender->GetSerial()->println("OK");
      return;
    case CONFIG_FILE_NOT_FOUND:
      sender->GetSerial()->println("ERR Config file not found");
      return;
    case CONFIG_WRITE_ERROR:
      sender->GetSerial()->println("ERR Failed to write config file");
      return;
    default:
      sender->GetSerial()->println("ERR Unknown error");
      return;
  }
}

SerialCommand cmd_getconf_("GETCONF", Commander::cmd_getconf);
SerialCommand cmd_setconf_("SETCONF", Commander::cmd_setconf);

Commander::Commander(Stream *serial, const char *term, const char *delim)
    : commander(serial, buf, sizeof(buf), term, delim) {
}

void Commander::begin() {
  commander.SetDefaultHandler(cmd_unrecognized);
  commander.AddCommand(&cmd_getconf_);
  commander.AddCommand(&cmd_setconf_);
}

void Commander::process() {
  commander.ReadSerial();
}