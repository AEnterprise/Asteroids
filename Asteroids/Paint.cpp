#include "stdafx.h"

void paint(HDC hdc) {
	HPEN po, pn;
	HBRUSH bo, bn;
	pn = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	bn = CreateSolidBrush(RGB(0, 0, 255));
	po = (HPEN)SelectObject(hdc, pn);
	int numbers[] = { 100, 100, 120, 100, 100, 120 };
	POINT points[3];
	generatePoints(points, numbers);
	Polygon(hdc, points, 3);
	
}

void generatePoints(POINT array[], int coordinates[], int amount) {
	
}