#include "ChordScene.h"
#include "Squidbox.h"

ChordScene::ChordScene(Squidbox *squidbox)
{
  this->squidbox = squidbox;
  type = CHORD_SCENE;
}

void ChordScene::init()
{
  Serial.println("ChordScene init");
}

void ChordScene::update()
{
  if (BLEMidiServer.isConnected())
  {
    // If we've got a connection, we send an A4 during one second, at full velocity (127)
    BLEMidiServer.noteOn(0, 69, 127);
    Serial.println("On");
    delay(1000);
    BLEMidiServer.noteOff(0, 69, 127); // Then we stop the note and make a delay of one second before returning to the beginning of the loop
    delay(1000);
    Serial.println("Off");
  }
}