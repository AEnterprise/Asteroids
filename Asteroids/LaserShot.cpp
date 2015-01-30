#include "stdafx.h"
#include "LaserShot.h"

float size = 10;
HPEN pnl;
HBRUSH bnl;
bool flying;

LaserShot::LaserShot()
{
	x = 200;
	y = 200;
	flying = false;
}


LaserShot::~LaserShot()
{
}

void LaserShot::render(HDC hdc) {
	if (!flying)
		return;
	pnl = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	bnl = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, pnl);
	SelectObject(hdc, bnl);
	Ellipse(hdc, x - size, y - size, x + size, y + size);
	DeleteObject(pnl);
	DeleteObject(bnl);

}

void LaserShot::launch() {
	flying = true;
}

void LaserShot::tick(int shipX, int shipY) {
	if (!flying) {
		x = shipX;
		y = shipY;
	}
	y -= 2;
	if (y < -5) {
		flying = false;
		x = shipX;
		y = shipY;
	}
}