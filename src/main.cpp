#include <iostream>
#include <string>
#define WINVER 0x0500
#include <windows.h>

#include "../include/keyboard.h"
#include "../include/mouse.h"
#include "../include/deck.h"

int main(int argc, char *argv[]){
  while (true){
    std::cout << "[0] Exit"  << std::endl <<
      "[1] Create a deck"    << std::endl <<
      "[2] Write a deckfile" << std::endl <<
      "Choose an option: ";
    int option;
    std::cin >> option;

    switch (option){
      case 1:
        // Pause for 5 seconds.
        Sleep(5000);

        // Allow for specifing a custom deck file
        if (argc > 1)
          readDeck(argv[1]);
        else
          readDeck("deck.txt");
        break;
      case 0:
        // Exit normally
        return 0;
        break;
      case 2:
        std::cout << "TBI";
        break;
      default:
        std::cout << "Unrecognised option";
        break;
    }
  }
}
