#include "stdafx.h"
#include "Star.h"

POINT points[]{
		{0, -5},
		{ 1, -3 },
		{ 3, -2 },
		{ 1, -1 },
		{ 0, 1 },
		{ -1, -1 },
		{-3, -2},
		{-1, -3}
};

Star::Star()
{
	x = 20;
	y = 20;
	scale = 2;
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

}
