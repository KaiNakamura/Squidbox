#pragma once

#include <SerialCommands.h>
#include "components/config/Config.h"

#define BUFFER_SIZE 4096

class Commander {
private:
  char buf[BUFFER_SIZE];
  SerialCommands commander;
  // static reference to allow access to config from handlers
  static Config *configRef;

public:
  Commander(Stream *serial, const char *term, const char *delim, Config &config);
  void begin();
  void process();

  static void cmd_getconf(SerialCommands *sender); // Command handler
  static void cmd_setconf(SerialCommands *sender); // Command handler
};