#include "../include/deck.h"

// Adds two of the same card with less delay
void addTwoCards(std::string card){
  // Try to add golden version first
  addGoldCard(card);
  Sleep(200);
  clickMouse();
  Sleep(200);

  // Add regular version
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

// Adds a golden card to the deck
void addGoldCard(std::string card){
  // Move mouse to search window
  moveMouse(0.5,0.92);
  clickMouse();
  Sleep(500);

  // Input card name
  typeString(card);
  Sleep(500);

  // Add card to deck
  moveMouse(0.35,0.3);
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
    parseLine(card);
  }

  // Close file
  infile.close();
}

// Parses a single line from a file
int parseLine(std::string line){
  std::string command;

  // Check for comment
  command = line.substr(0,1);
  if (command == "/" || command == "")
    return(COMMENT);
  // Check for deck name
  else if (command == "#"){
    int tmp = line.find(' ', 0);
    std::string name = line.substr(tmp);

    // Make sure name actually exists
    if (name.length() > 1){
      // Extract name
      name = name.substr(1);
      // Input name
      moveMouse(0.78, 0.07);
      clickMouse();
      Sleep(200);
      typeString(name);
    }

    Sleep(500);
    return(RENAMED_DECK);
  }
  // Check for number of cards
  else if (command == "1"){
    std::string card = line.substr(2);
    addCard(card);
    Sleep(500);
    return(CARD_ADDED);
  }
  else if (command == "2"){
    std::string card = line.substr(2);
    addTwoCards(card);
    Sleep(500);
    return(CARD_ADDED);
  }

  // std::cout << command;
  addCard(line);
  Sleep(500);

  return(CARD_ADDED);
}
