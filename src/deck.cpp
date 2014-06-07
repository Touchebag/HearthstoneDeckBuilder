#include "deck.h"

// Adds two of the same card with less delay
void addTwoCards(std::string card){
  addCard(card);
  Sleep(200);
  clickMouse();
}

// Adds a card to the deck
void addCard(std::string card){
  // Move mouse to search window
  moveMouse(0.5,0.92);
  clickMouse();
  Sleep(500);

  // Input card name
  typeString(card);
  Sleep(500);

  // Add card to deck
  moveMouse(0.2,0.3);
  clickMouse();
}

// Reads a deck from a file
void readDeck(std::string file){
  // Open file
  std::ifstream infile;
  infile.open(file.c_str());

  // The current card
  std::string card;

  while (std::getline(infile, card)){
    addCard(card);
    Sleep(500);
  }

  // Close file
  infile.close();
}
