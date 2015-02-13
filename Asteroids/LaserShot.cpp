#include "stdafx.h"
#include "LaserShot.h"

HPEN pnl = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
HBRUSH bnl = CreateSolidBrush(RGB(255, 0, 0));
static int id, shotX, shotY;
float size = 10;

LaserShot::LaserShot(int shotID)
{
	flying = false;
	id = shotID;
	shotX = 200;
	shotY= 200;
	laserPoints[0] = { -2, -2 };
	laserPoints[1] = { -2, 15 };
	laserPoints[2] = { 2, 15 };
	laserPoints[3] = { 2, -2 };
}


LaserShot::~LaserShot()
{
}

void LaserShot::render(HDC hdc) {
	if (!flying)
		return;
	SelectObject(hdc, pnl);
	SelectObject(hdc, bnl);
	movePoints(laserPoints, shotX, shotY, 4);
	Polygon(hdc, laserPoints, 4);
	movePoints(laserPoints, -shotX, -shotY, 4);
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
		a
	}
}