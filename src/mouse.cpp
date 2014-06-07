#include "mouse.h"

void moveMouse(int x, int y){
 INPUT Input={0};
 Input.type = INPUT_MOUSE;

 Input.mi.dx = x;
 Input.mi.dy = y;

 Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

 SendInput(1,&Input,sizeof(INPUT));
}
