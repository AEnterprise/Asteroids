#include "stdafx.h"

bool showMouse = false;

void onKeyDown(WPARAM key) {
	if (::GetKeyState(VK_CONTROL)) {
		showMouse = !showMouse;
		ShowCursor(showMouse);
	}
}

void onKeyUp(WPARAM key){
	if (key == 27){
		exit(0);
	}
}
void leftclick(){
	fire();
}
void rightclick(){

}