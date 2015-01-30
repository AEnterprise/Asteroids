#include "stdafx.h"
#include "Star.h"

int x;
int y;

POINT static points[] = {
		{ 0, -5 },
		{ 1, -3 },
		{ 3, -2 },
		{ 1, -1 },
		{ 0, 1 },
		{ -1, -1 },
		{ -3, -2 },
		{ -1, -3 } };

Star::Star(int newX, int newY, float newScale)
{
	x = newX;
	y = newY;
	scale = newScale;
}


Star::~Star()
{
}

void Star::render(HDC hdc) {
	HPEN pn;
	HBRUSH bn;
	pn = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	bn = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, pn);
	SelectObject(hdc, bn);

	movePoints(points, x, y, 8);
	scalePoints(points, scale, 8);

	Polygon(hdc, points, 8);

	scalePoints(points, 1 / scale, 8);
	movePoints(points, -x, -y, 8);
	DeleteObject(pn);
	DeleteObject(bn);

}

void Star::setX(int newX) {
	x = newX;
}

void Star::setY(int newY) {
	y = newY;
}

void Star::setScale(float newScale) {
	scale = newScale;
}

void Star::moveDown(int windowHeight) {
	y++;
	if (y > windowHeight) {
		y = -3;
	}
}
