#pragma once

#include "scene/Scene.h"

class ChordScene : public Scene
{
public:
  ChordScene(Squidbox *squidbox);
  void playChord(int buttonPin, int note1, int note2, int note3);
  void init();
  void update();
};

// enum Note { // needs editing
//     C2 = 65,
//     CSHARP2 = 69,
//     D2 = 73,
//     DSHARP2 = 78,
//     E2 = 82,
//     F2 = 87,
//     FSHARP2 = 92,
//     G2 = 98,
//     GSHARP2 = 104,
//     A2 = 110,
//     ASHARP2 = 117,
//     B2 = 123,
//     C3 = 130,
//     CSHARP3 = 138,
//     D3 = 146,
//     DSHARP3 = 155,
//     E3 = 164,
//     F3 = 174,
//     FSHARP3 = 185,
//     G3 = 196,
//     GSHARP3 = 207,
//     A3 = 220,
//     ASHARP3 = 233,
//     B3 = 246,
//     C4 = 261,
//     CSHARP4 = 277,
//     D4 = 293,
//     DSHARP4 = 311,
//     E4 = 329,
//     F4 = 349,
//     FSHARP4 = 370,
//     G4 = 392,
//     GSHARP4 = 415,
//     A4 = 440,
//     ASHARP4 = 466,
//     B4 = 493,
//     C5 = 523,
//     CSHARP5 = 554,
//     D5 = 587,
//     DSHARP5 = 622,
//     E5 = 659,
//     F5 = 698,
//     FSHARP5 = 740,
//     G5 = 784,
//     GSHARP5 = 831,
//     A5 = 880,
//     ASHARP5 = 932,
//     B5 = 988,
//     C6 = 1047,
// };