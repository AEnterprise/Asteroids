#include "stdafx.h"
#include "Target.h"

HBRUSH targetBrush;

Target::Target()
{
	x = 500;
	y = 200;
	targetBrush = CreateSolidBrush(RGB(255, 255, 0));
	numPoints = 4;
	points[0] = { -25, -25 };
	points[1] = { -25, 25 };
	points[2] = { 25, 25 };
	points[3] = { 25, -25 };
	movePoints(points, x, y, 4);
	alive = true;
	health = 3;
}


Target::~Target()
{
}

void Target::render(HDC hdc){
	if (!alive)
		return;
	SelectObject(hdc, targetBrush);
	Polygon(hdc, points, numPoints);

}

void Target::tick(){

}

void Target::hit(int strenght) {
	health -= strenght;
	if (health < 0) {
		alive = false;
	}
}

void Target::setX(int newX) {
	x = newX;
}

void Target::setY(int newY) {
	y = newY;
}

POINT* Target::getPoints(){
	return points;
}

int Target::getNumPoints(){
	return numPoints;
}

bool Target::isAlive(){
	return alive;
}