#include "stdafx.h"

SpaceShip ship;
Star* star[40];
int width, height;

void paint(HDC hdc) {
	
	for (int t = 0; t < 40; t++) {
		star[t]->render(hdc);
	}
	ship.render(hdc);
}

void init(HWND hwnd) {
	RECT rect;
	if (GetWindowRect(hwnd, &rect)) {
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
	}
	for (int t = 0; t < 40; t++) {
		star[t] = new Star(rand() % width, rand() % height, rand() % 2 + 1);
	}
}