#include <iostream>
#include <string>
#define WINVER 0x0500
#include <windows.h>
// using namespace std;

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

void typeString(std::string str){
  for (std::string::iterator it = str.begin(); it != str.end(); ++it){
    pressKey(*it);
  }
  sendEnter();
}

int main(int argc, char *argv[]){
  // Pause for 5 seconds.
  Sleep(5000);

  typeString("Ysera");

  // Exit normally
  return 0;
}
