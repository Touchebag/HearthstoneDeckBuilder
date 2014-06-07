#include "mouse.h"

void moveMouse(double x, double y){
  int nx = round(x * 65535.0);
  int ny = round(y * 65535.0);

  INPUT Input={0};
  Input.type = INPUT_MOUSE;

  Input.mi.dx = nx;
  Input.mi.dy = ny;

  Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

  SendInput(1,&Input,sizeof(INPUT));
}

void clickMouse(){
  INPUT Input={0};
  Input.type = INPUT_MOUSE;

  Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
  SendInput(1,&Input,sizeof(INPUT));
}
