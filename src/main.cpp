#include <iostream>
#include <string>
#define WINVER 0x0500
#include <windows.h>

#include "../include/keyboard.h"
#include "../include/mouse.h"
#include "../include/deck.h"

int main(int argc, char *argv[]){
  // Pause for 5 seconds.
  Sleep(5000);

  // Allow for specifing a custom deck file
  if (argc > 1)
    readDeck(argv[1]);
  else
    readDeck("deck.txt");

  // Exit normally
  return 0;
}
