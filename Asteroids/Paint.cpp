#include "stdafx.h"

void paint(HDC hdc) {
	HPEN po, pn;
	HBRUSH bo, bn;
	pn = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	bn = CreateSolidBrush(RGB(0, 0, 255));
	po = (HPEN)SelectObject(hdc, pn);
	POINT points[3];
	points[0].x = 100;
	points[0].y = 100;
	points[1].x = 500;
	points[1].y = 100;
	points[2].x = 300;
	points[2].y = 200;
	Polygon(hdc, points, 3);
	
}