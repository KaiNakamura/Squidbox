#pragma once

#include <USB-MIDI.h>
#include <BLEMidi.h>

class MIDIServer
{
public:
  static void begin(const char *name);
  static void noteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  static void noteOff(uint8_t channel, uint8_t note, uint8_t velocity);
};