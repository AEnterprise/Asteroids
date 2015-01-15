#include "stdafx.h"
#include "SpaceShip.h"

POINT TOP[]{
		{0, 0},
		{ 20, 20 },
		{ -20, 20 }};

POINT LEFTWING[] {
		{-20, 50},
		{ -40, 80 },
		{-25, 80},
		{-20, 70}};

POINT RIGHTWING[] {
		{20, 50},
		{40, 80},
		{25,80},
		{20, 70}
};

SpaceShip::SpaceShip()
{
	x = 500;
	y = 250;
}


SpaceShip::~SpaceShip()
{
}

void SpaceShip::render(HDC hdc) {
	HPEN pn;
	HBRUSH bn;
	pn = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	bn = CreateSolidBrush(RGB(0, 255, 0));
	SelectObject(hdc, pn);
	SelectObject(hdc, bn);
	
	movePoints(TOP, x, y, 3);
	movePoints(LEFTWING, x, y, 4);
	movePoints(RIGHTWING, x, y, 4);

	Polygon(hdc, TOP, 3);
	Rectangle(hdc, x - 20, y + 20, x + 20, y + 80);
	Polygon(hdc, LEFTWING, 4);
	Polygon(hdc, RIGHTWING, 4);
}
