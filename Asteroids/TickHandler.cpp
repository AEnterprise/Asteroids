#include "stdafx.h"

const int NUMSTARS = 60;

SpaceShip* ship;
Star* star[NUMSTARS];
int width, height;
RECT rect, background;
HBRUSH backgroundBrush;

void tick() {
	for (int t = 0; t < NUMSTARS; t++) {
		star[t]->moveDown(width, height);
	}
	ship->tick();
	moveShip();
}

void paint(HDC hdc) {
	backgroundBrush = CreateSolidBrush(RGB(0, 0, 0));
	FillRect(hdc, &background, backgroundBrush);
	for (int t = 0; t < NUMSTARS; t++) {
		star[t]->render(hdc);
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
	initShotMananger();
}

void moveShip() {
	POINT mouse;
	GetCursorPos(&mouse);
	ship->moveToMouse(mouse.x - rect.left, mouse.y - rect.top - 50);
}

void windowResize(HWND hwnd) {
	if (GetWindowRect(hwnd, &rect)) {
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
		GetClientRect(hwnd, &background);
		for (int t = 0; t < NUMSTARS; t++) {
			if (star[t] == NULL)
				continue;
			star[t]->starX = rand() % width;
			star[t]->starY = rand() % height;
		}
	}
}