#include <iostream>
#include <string>
#define WINVER 0x0500
#include <windows.h>

#include "keyboard.h"
#include "mouse.h"

int main(int argc, char *argv[]){
  // Pause for 5 seconds.
  // Sleep(5000);

  // typeString("Ysera");

  moveMouse(32768,32768);

  // Exit normally
  return 0;
}
