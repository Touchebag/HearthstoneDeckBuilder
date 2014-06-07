#ifndef Keyboard_H
#define Keyboard_H

#define WINVER 0x0500
#include <windows.h>
#include <string>
#include <iostream>

void pressKey(char);
void typeString(std::string);
void sendEnter();

#endif
