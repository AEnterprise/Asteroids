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
}

void paint(HDC hdc) {
	for (int t = 0; t < NUMSTARS; t++) {
		star[t]->render(hdc);
	}
	ship->render(hdc);
}

void init(HWND hwnd) {
	ship = new SpaceShip;
	if (GetWindowRect(hwnd, &rect)) {
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
	}
	for (int t = 0; t < NUMSTARS; t++) {
		star[t] = new Star(rand() % width, rand() % height, rand() % 2 + 1);
	}
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
		ship->fire();
		break;
	}
}