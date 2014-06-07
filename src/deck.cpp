#include "deck.h"

void addTwoCards(std::string card){
  addCard(card);
  Sleep(200);
  clickMouse();
}

void addCard(std::string card){
  moveMouse(0.5,0.92);
  clickMouse();

  Sleep(500);
  typeString(card);
  Sleep(500);
  moveMouse(0.2,0.3);
  clickMouse();
}

void readDeck(std::string file){
  std::ifstream infile;
  infile.open(file.c_str());

  std::string card;
  while (std::getline(infile, card)){
    addCard(card);
    Sleep(500);
  }

  infile.close();
}
