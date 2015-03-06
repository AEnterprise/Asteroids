#include "stdafx.h"
#include "Target.h"

Target::Target()
{
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