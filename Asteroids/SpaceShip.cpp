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

POINT BODY[] {
		{-20, 20},
		{ 20, 20 },
		{ 20, 80 },
		{-20, 80}
};
float scale = 3;

SpaceShip::SpaceShip()
{
	x = 250;
	y = 250;
}


SpaceShip::~SpaceShip()
{
}

void SpaceShip::render(HDC hdc) {
	HPEN pn;
	HBRUSH bn;
	pn = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	bn = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, pn);
	SelectObject(hdc, bn);

	
	
	scalePoints(TOP, scale, 3);
	scalePoints(LEFTWING, scale, 4);
	scalePoints(RIGHTWING, scale, 4);
	scalePoints(BODY, scale, 4);
	movePoints(TOP, x, y, 3);
	movePoints(LEFTWING, x, y, 4);
	movePoints(RIGHTWING, x, y, 4);
	movePoints(BODY, x, y, 4);

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
}
