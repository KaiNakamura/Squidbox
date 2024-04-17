#include "MIDIServer.h"

/**
 * @brief This class was intended to be a wrapper around the USB-MIDI library
 * and the BLEMidi library. But the board we are using does not currently
 * support USB-MIDI. If the board is switched to a different one, USB-MIDI could
 * easily be implemented by adding the corresponding functions to the ones in
 * this wrapper.
 *
 */

void MIDIServer::begin(const char *name) {
  BLEMidiServer.begin(name);
  BLEMidiServer.enableDebugging();
}

void MIDIServer::noteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (BLEMidiServer.isConnected()) {
    BLEMidiServer.noteOn(note, velocity, channel);
  }
}

void MIDIServer::noteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (BLEMidiServer.isConnected()) {
    BLEMidiServer.noteOff(note, velocity, channel);
  }
}
