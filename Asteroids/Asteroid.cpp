#include "stdafx.h"
#include "Asteroid.h"


Asteroid::Asteroid()
{
	health = 10;
	x = 500;
	y = 200;
	brush = CreateSolidBrush(RGB(255, 255, 0));
	numPoints = 4;
	points[0] = { -25, -25 };
	points[1] = { -25, 25 };
	points[2] = { 25, 25 };
	points[3] = { 25, -25 };
	movePoints(points, x, y, 4);
	alive = true;
}


Asteroid::~Asteroid()
{
}

void Asteroid::render(HDC hdc) {
	if (!alive)
		return;
	SelectObject(hdc, brush);
	Polygon(hdc, points, numPoints);
}

POINT* Asteroid::getPoints(){
	return points;
}

int Asteroid::getNumPoints(){
	return numPoints;
}

void Asteroid::tick(){

}