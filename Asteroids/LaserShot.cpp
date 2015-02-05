#include "stdafx.h"
#include "LaserShot.h"

HPEN pnl;
HBRUSH bnl;
static int id, shotX, shotY;
float size = 10;

LaserShot::LaserShot(int shotID)
{
	flying = false;
	id = shotID;
	shotX = 200;
	shotY= 200;
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
	Ellipse(hdc, shotX - size, shotY - size, shotX + size, shotY + size);
	DeleteObject(pnl);
	DeleteObject(bnl);

}

void LaserShot::launch() {
	flying = true;
}

void LaserShot::tick(int shipX, int shipY) {
	if (!flying) {
		shotX = shipX;
		shotY = shipY;
	} else {
		shotY -= 6;
		if (shotY < -5) {
			flying = false;
			reclaimShot(id);
		}
	}
}