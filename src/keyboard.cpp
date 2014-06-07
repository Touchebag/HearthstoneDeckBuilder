#include "keyboard.h"

// Sends a single keystroke
void pressKey(char key){
  INPUT ip;
  ip.type = INPUT_KEYBOARD;
  ip.ki.time = 0;
  ip.ki.dwFlags = KEYEVENTF_UNICODE; // Specify the key as a unicode character
  ip.ki.wScan = key; // Which keypress to simulate
  ip.ki.wVk = 0;
  ip.ki.dwExtraInfo = 0;
  SendInput(1, &ip, sizeof(INPUT));
}

// Sends a sequence of character keystrokes
void typeString(std::string str){
  char prev = ' ';

  // Loop through entire string
  for (std::string::iterator it = str.begin(); it != str.end(); ++it){

    // Delay repeated keystrokes
    if (prev == *it)
      Sleep(200);
    prev = *it;

    // Send keystroke
    pressKey(*it);
  }

  sendEnter();
}

// Sends a return keystroke
void sendEnter(){
  INPUT ip;
  ip.type = INPUT_KEYBOARD;
  ip.ki.time = 0;
  ip.ki.dwFlags = KEYEVENTF_UNICODE; // Specify the key as a unicode character
  ip.ki.wScan = 0; // Which keypress to simulate
  ip.ki.wVk = 0x0D;
  ip.ki.dwExtraInfo = 0;
  SendInput(1, &ip, sizeof(INPUT));
}

