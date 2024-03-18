#pragma once

// This is an error handle function, that can be used to print a specific error
// with the file name and the line number.
#define print_error(msg) { Serial.printf("\nError: %s | %s: %d\n\n", msg, __FILE__, __LINE__); }
