#include <iostream>
#include <string>
#define WINVER 0x0500
#include <windows.h>

#include "../include/keyboard.h"
#include "../include/mouse.h"
#include "../include/deck.h"

int main(int argc, char *argv[]){
  system("cls");

  while (true){
    std::cout << "[0] Exit"  << std::endl <<
      "[1] Create a deck"    << std::endl <<
      "[2] Write a deckfile" << std::endl <<
      "Choose an option: ";
    int option;
    std::cin >> option;
    std::string file;

    switch (option){
      case 1:
        // Allow for specifing a custom deck file
        std::cout << "Please specify a deck file. If no file is specified the default (deck.txt) will be read." << std::endl;
        std::cin >> file;

        // Pause for 5 seconds.
        std::cout << "Preparing to create deck from file \"" << file <<"\". Please switch to the Hearthstone window." << std::endl;
        Sleep(5000);

        if (file.empty())
          readDeck(file);
        else
          readDeck("deck.txt");
        break;
      case 0:
        // Exit normally
        return 0;
        break;
      case 2:
        std::cout << "TBI" << std::endl;
        break;
      default:
        std::cout << "Unrecognised option" << std::endl;
        break;
    }

    system("pause");
  }
}
