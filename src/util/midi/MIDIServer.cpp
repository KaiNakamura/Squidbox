#include "MIDIServer.h"

// USBMIDI_CREATE_DEFAULT_INSTANCE();

void MIDIServer::begin(const char *name)
{
  // MIDI.begin();
  BLEMidiServer.begin(name);
  BLEMidiServer.enableDebugging();
}

void MIDIServer::noteOn(uint8_t channel, uint8_t note, uint8_t velocity)
{
  // MIDI.sendNoteOn(note, velocity, channel);
  if (BLEMidiServer.isConnected())
  {
    BLEMidiServer.noteOn(note, velocity, channel);
  }
}

void MIDIServer::noteOff(uint8_t channel, uint8_t note, uint8_t velocity)
{
  // MIDI.sendNoteOff(note, velocity, channel);
  if (BLEMidiServer.isConnected())
  {
    BLEMidiServer.noteOff(note, velocity, channel);
  }
}
