#ifndef Deck_h
#define Deck_h

#include <iostream>
#include <fstream>
#include <sstream>

#include "mouse.h"
#include "keyboard.h"

// Messages from parseline
enum {
  CARD_ADDED,
  CARDS_ADDED,
  RENAMED_DECK,
  COMMENT,
};

// Adds two of the same card with less delay
void addTwoCards(std::string);
// Adds a card to the deck
void addCard(std::string);
// Adds a golden card to the deck
void addGoldCard(std::string);

// Reads a deck from a file
void readDeck(std::string);

// Parses a single line from a file
int parseLine(std::string);

#endif
