#pragma once

struct ChordType
{
  int numNotes;
  int *offsets;
};

static const ChordType TRIAD = {3, new int[3]{0, 2, 4}};