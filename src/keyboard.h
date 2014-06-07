#ifndef Keyboard_H
#define Keyboard_H

#define WINVER 0x0500
#include <windows.h>
#include <iostream>

// Sends a single keystroke
void pressKey(char);
// Sends a sequence of character keystrokes
void typeString(std::string);
// Sends a return keystroke
void sendEnter();

#endif
