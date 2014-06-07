#ifndef Deck_h
#define Deck_h

#include <iostream>
#include <fstream>
#include <sstream>

#include "mouse.h"
#include "keyboard.h"

// Adds two of the same card with less delay
void addCard(std::string);
// Adds a card to the deck
void addTwoCards(std::string);

// Reads a deck from a file
void readDeck(std::string);

#endif
