#pragma once

#include <Arduino.h>
#include <vector>

#define MAX_BUTTONS 8

struct Preset {
    String name;
    String description;
    std::array<std::vector<int>, MAX_BUTTONS> notes;
};
