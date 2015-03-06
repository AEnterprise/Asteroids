#include "stdafx.h"

int width, height;
RECT rect, background;
HBRUSH backgroundBrush = CreateSolidBrush(RGB(0, 0, 0));

void tick() {
	for (int t = 0; t < Vars::NUMSTARS; t++) {
		Vars::star[t]->moveDown(width, height);
	}
	Vars::ship->tick();
	moveShip();
	for (int t = 0; t < Vars::NUMTARGETS; t++){
		for (int i = 0; i < Vars::NUMSHOTS; i++) {
			if (Vars::targets[t]->isAlive() && Vars::fired[i] && hitTest(Vars::targets[t]->getPoints(), Vars::targets[t]->getNumPoints(), Vars::shots[i]->getPoints(), 4)) {
				Vars::targets[t]->hit(Vars::shots[i]->getStrength());
				reclaimShot(i);
			}
		}
	}
}

void paint(HDC hdc) {
	FillRect(hdc, &background, backgroundBrush);
	for (int t = 0; t < Vars::NUMSTARS; t++) {
		Vars::star[t]->render(hdc);
	}
	for (int t = 0; t < Vars::NUMTARGETS; t++) {
		Vars::targets[t]->render(hdc);
	}
	Vars::ship->render(hdc);
	renderShots(hdc);
}

void init(HWND hwnd) {
	windowResize(hwnd);
	ShowCursor(false);
	Vars::ship = new SpaceShip;
	for (int t = 0; t < Vars::NUMSTARS; t++) {
		Vars::star[t] = new Star(rand() % width, rand() % height, rand() % 2 + 1);
	}
	for (int t = 0; t < Vars::NUMTARGETS; t++) {
		Vars::targets[t] = new Asteroid();
	}
	initShotMananger();
}

void moveShip() {
	POINT mouse;
	GetCursorPos(&mouse);
	Vars::ship->moveToMouse(mouse.x - rect.left, mouse.y - rect.top - 50, background);
}

void windowResize(HWND hwnd) {
	if (GetWindowRect(hwnd, &rect)) {
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
		GetClientRect(hwnd, &background);
		for (int t = 0; t < Vars::NUMSTARS; t++) {
			if (Vars::star[t] == NULL)
				continue;
			Vars::star[t]->setX(rand() % width);
			Vars::star[t]->setY(rand() % height);
		}
	}
}