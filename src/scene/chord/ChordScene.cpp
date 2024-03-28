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
    // If we've got a connection, full velocity (127)

  // A Major Diatonic Chords
    if (this->squidbox->getButton(1)->isPressed())    
    {
      BLEMidiServer.noteOn(0, 93, 127); //A6
      BLEMidiServer.noteOn(0, 97, 127); //C#7
      BLEMidiServer.noteOn(0, 100, 127); //E7
      Serial.println("On");
      delay(1000);
      BLEMidiServer.noteOff(0, 93, 127); //A6
      BLEMidiServer.noteOff(0, 97, 127); //C#7
      BLEMidiServer.noteOff(0, 100, 127); //E7
      Serial.println("Off");
    }

    if (this->squidbox->getButton(2)->isPressed())
    {
      
      BLEMidiServer.noteOn(0, 95, 127); //B6
      BLEMidiServer.noteOn(0, 98, 127); //D7
      BLEMidiServer.noteOn(0, 102, 127); //F#7
      Serial.println("On");
      delay(1000);
      BLEMidiServer.noteOff(0, 95, 127); //B6
      BLEMidiServer.noteOff(0, 98, 127); //D7
      BLEMidiServer.noteOff(0, 102, 127); //F#7 
      Serial.println("Off");
    }

    if (this->squidbox->getButton(3)->isPressed())
    {
      BLEMidiServer.noteOn(0, 97, 127); //C#7
      BLEMidiServer.noteOn(0, 101, 127); //E7
      BLEMidiServer.noteOn(0, 104, 127); //G#7
      Serial.println("On");
      delay(1000);
      BLEMidiServer.noteOff(0, 97, 127); //C#7
      BLEMidiServer.noteOff(0, 100, 127); //E7
      BLEMidiServer.noteOff(0, 104, 127); //G#7
      Serial.println("Off");
    }

    if (this->squidbox->getButton(4)->isPressed())
    {
      BLEMidiServer.noteOn(0, 98, 127); //D7
      BLEMidiServer.noteOn(0, 102, 127); //F#7
      BLEMidiServer.noteOn(0, 105, 127); //A7
      Serial.println("On");
      delay(1000);
      BLEMidiServer.noteOff(0, 98, 127); //D7
      BLEMidiServer.noteOff(0, 102, 127); //F#7
      BLEMidiServer.noteOff(0, 105, 127); //A7
      Serial.println("Off");
    }

    if (this->squidbox->getButton(5)->isPressed()) { 
      BLEMidiServer.noteOn(0, 100, 127); //E7
      BLEMidiServer.noteOn(0, 104, 127); //G#7
      BLEMidiServer.noteOn(0, 107, 127); //B7
      Serial.println("On");
      delay(1000);
      BLEMidiServer.noteOff(0, 100, 127); //E7
      BLEMidiServer.noteOff(0, 104, 127); //G#7
      BLEMidiServer.noteOff(0, 107, 127); //B7
      Serial.println("Off");
    }

    if (this->squidbox->getButton(6)->isPressed())
    {
      BLEMidiServer.noteOn(0, 101, 127); //F#7
      BLEMidiServer.noteOn(0, 105, 127); //A7
      BLEMidiServer.noteOn(0, 108, 127); //C8
      Serial.println("On");
      delay(1000);
      BLEMidiServer.noteOff(0, 102, 127); //F7
      BLEMidiServer.noteOff(0, 105, 127); //A7
      BLEMidiServer.noteOff(0, 108, 127); //C8
      Serial.println("Off");
    }

    if (this->squidbox->getButton(7)->isPressed())
    {
      BLEMidiServer.noteOn(0, 104, 127); //G#7
      BLEMidiServer.noteOn(0, 107, 127); //B7
      BLEMidiServer.noteOn(0, 110, 127); //D8
      Serial.println("On");
      delay(1000);
      BLEMidiServer.noteOff(0, 104, 127); //G#7
      BLEMidiServer.noteOff(0, 107, 127); //B7
      BLEMidiServer.noteOff(0, 110, 127); //D8
      Serial.println("Off");
    }

    if (this->squidbox->getButton(8)->isPressed())
    {
      BLEMidiServer.noteOn(0, 105, 127); //A7
      BLEMidiServer.noteOn(0, 109, 127); //C#8
      BLEMidiServer.noteOn(0, 112, 127); //E8
      Serial.println("On");
      delay(1000);
      BLEMidiServer.noteOn(0, 105, 127); //A7
      BLEMidiServer.noteOn(0, 109, 127); //C#8
      BLEMidiServer.noteOn(0, 112, 127); //E8
      Serial.println("Off");
    }
    
  }
}