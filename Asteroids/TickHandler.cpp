#include "stdafx.h"

const int NUMSTARS = 60;

SpaceShip* ship;
Star* star[NUMSTARS];
int width, height;
RECT rect;

void tick() {
	for (int t = 0; t < NUMSTARS; t++) {
		star[t]->moveDown(height);
	}
	ship->tick();
	moveShip();
}

void paint(HDC hdc) {
	for (int t = 0; t < NUMSTARS; t++) {
		star[t]->render(hdc);
	}
	ship->render(hdc);
	renderShots(hdc);
}

void init(HWND hwnd) {
	ShowCursor(false);
	ship = new SpaceShip;
	if (GetWindowRect(hwnd, &rect)) {
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
	}
	for (int t = 0; t < NUMSTARS; t++) {
		star[t] = new Star(rand() % width, rand() % height, rand() % 2 + 1);
	}
	initShotMananger();
}

void keydown(WPARAM wParam){
	switch (wParam) {
	case 'Z':
		ship->up = true;
		break;
	case 'Q': 
		ship->left = true;
		break;
	case 'S':
		ship->down = true;
		break;
	case 'D':
		ship->right = true;
	}
}
void keyup(WPARAM wParam) {
	switch (wParam) {
	case 'Z':
		ship->up = false;
		break;
	case 'Q':
		ship->left = false;
		break;
	case 'S':
		ship->down = false;
		break;
	case 'D':
		ship->right = false;
		break;
	case ' ':
		fire();
		break;
	}
}

void moveShip() {
	POINT mouse;
	GetCursorPos(&mouse);
	ship->moveToMouse(mouse.x - rect.left, mouse.y - rect.top - 50);
}

void click() {
	fire();
}