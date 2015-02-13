#include "stdafx.h"

const int NUMSTARS = 60;
const int NUMTARGETS = 1;

SpaceShip* ship;
Star* star[NUMSTARS];
Target* targets[NUMTARGETS];
int width, height;
RECT rect, background;
HBRUSH backgroundBrush = CreateSolidBrush(RGB(0, 0, 0));

void tick() {
	for (int t = 0; t < NUMSTARS; t++) {
		star[t]->moveDown(width, height);
	}
	ship->tick();
	moveShip();
}

void paint(HDC hdc) {
	FillRect(hdc, &background, backgroundBrush);
	for (int t = 0; t < NUMSTARS; t++) {
		star[t]->render(hdc);
	}
	for (int t = 0; t < NUMTARGETS; t++) {
		targets[t]->render(hdc);
	}
	ship->render(hdc);
	renderShots(hdc);
}

void init(HWND hwnd) {
	windowResize(hwnd);
	ShowCursor(false);
	ship = new SpaceShip;
	for (int t = 0; t < NUMSTARS; t++) {
		star[t] = new Star(rand() % width, rand() % height, rand() % 2 + 1);
	}
	for (int t = 0; t < NUMTARGETS; t++) {
		targets[t] = new Target();
	}
	initShotMananger();
}

void moveShip() {
	POINT mouse;
	GetCursorPos(&mouse);
	ship->moveToMouse(mouse.x - rect.left, mouse.y - rect.top - 50, background);
}

void windowResize(HWND hwnd) {
	if (GetWindowRect(hwnd, &rect)) {
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
		GetClientRect(hwnd, &background);
		for (int t = 0; t < NUMSTARS; t++) {
			if (star[t] == NULL)
				continue;
			star[t]->setX(rand() % width);
			star[t]->setY(rand() % height);
		}
	}
}