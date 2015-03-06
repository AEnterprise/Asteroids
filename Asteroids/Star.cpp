#include "stdafx.h"
#include "Star.h"

HPEN starPen;
HBRUSH starBrush;

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
	starX = newX;
	starY = newY;
	scale = newScale;
	starPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	starBrush = CreateSolidBrush(RGB(255, 255, 255));
}


Star::~Star()
{
}

void Star::render(HDC hdc) {
	 
	
	SelectObject(hdc, starPen);
	SelectObject(hdc, starBrush);

	movePoints(points, starX, starY, 8);
	scalePoints(points, scale, 8);

	Polygon(hdc, points, 8);

	scalePoints(points, 1 / scale, 8);
	movePoints(points, -starX, -starY, 8);

}

void Star::setX(int newX) {
	starX = newX;
}

void Star::setY(int newY) {
	starY = newY;
}

void Star::setScale(float newScale) {
	scale = newScale;
}

void Star::moveDown(int windowWith, int windowHeight) {
	starY++;
	if (starY > windowHeight) {
		starY = -3;
		starX = rand() % windowWith;
	}
}
