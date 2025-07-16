#pragma once

#include <SerialCommands.h>
#include "components/config/Config.h"

#define BUFFER_SIZE 4096

class Commander {
private:
  char buf[BUFFER_SIZE];
  SerialCommands commander;

public:
  Commander(Stream *serial, const char *term, const char *delim);
  void begin();
  void process();

  static void cmd_getconf(SerialCommands *sender); // Command handler
  static void cmd_setconf(SerialCommands *sender); // Command handler
};