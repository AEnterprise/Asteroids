#include "stdafx.h"
#include "SpaceShip.h"

const int NUMSHOTS = 5;
int shotNumber;

LaserShot* shots[NUMSHOTS];

POINT static TOP[]{
		{0, 0},
		{ 20, 20 },
		{ -20, 20 }};

POINT static LEFTWING[] {
		{-20, 50},
		{ -40, 80 },
		{-25, 80},
		{-20, 70}};

POINT static RIGHTWING[] {
		{20, 50},
		{40, 80},
		{25,80},
		{20, 70}
};

POINT static BODY[] {
		{-20, 20},
		{ 20, 20 },
		{ 20, 80 },
		{-20, 80}
};
float scale = 1;

HPEN pn;
HBRUSH bn;

SpaceShip::SpaceShip()
{
	x = 500;
	y = 300;
	up = false;
	down = false;
	left = false;
	right = false;
	shotNumber = 0;
	for (int t = 0; t < NUMSHOTS; t++) {
		shots[t] = new LaserShot;
	}
}


SpaceShip::~SpaceShip()
{
}

void SpaceShip::render(HDC hdc) {
	for (int t = 0; t < NUMSHOTS; t++) {
		shots[t]->render(hdc);
	}
	scalePoints(TOP, scale, 3);
	scalePoints(LEFTWING, scale, 4);
	scalePoints(RIGHTWING, scale, 4);
	scalePoints(BODY, scale, 4);
	movePoints(TOP, x, y, 3);
	movePoints(LEFTWING, x, y, 4);
	movePoints(RIGHTWING, x, y, 4);
	movePoints(BODY, x, y, 4);

	pn = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	bn = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, pn);
	SelectObject(hdc, bn);

	Polygon(hdc, TOP, 3);
	bn = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(hdc, bn);
	Polygon(hdc, BODY, 4);
	bn = CreateSolidBrush(RGB(0, 255, 0));
	SelectObject(hdc, bn);
	Polygon(hdc, LEFTWING, 4);
	Polygon(hdc, RIGHTWING, 4);
	DeleteObject(pn);
	DeleteObject(bn);

	movePoints(TOP, -x, -y, 3);
	movePoints(LEFTWING, -x, -y, 4);
	movePoints(RIGHTWING, -x, -y, 4);
	movePoints(BODY, -x, -y, 4);
	scalePoints(TOP, 1/scale, 3);
	scalePoints(LEFTWING, 1/scale, 4);
	scalePoints(RIGHTWING, 1/scale, 4);
	scalePoints(BODY, 1/scale, 4);

	
	
}

void SpaceShip::tick() {
	if (down)
		y+=3;
	if (up)
		y-=3;
	if (left)
		x-=3;
	if (right)
		x+=3;
	for (int t = 0; t < NUMSHOTS; t++) {
		shots[t]->tick(x, y);
	}
}

void SpaceShip::fire() {
	if (shotNumber <= NUMSHOTS)
		shots[shotNumber]->launch();
	shotNumber++;
}