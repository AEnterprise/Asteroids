#include "stdafx.h"
#include "Target.h"


Target::Target()
{
	x = 500;
	y = 30;
}


Target::~Target()
{
}

void Target::render(HDC hdc){

}

void Target::tick(){

}

void Target::setX(int newX) {
	x = newX;
}

void Target::setY(int newY) {
	y = newY;
}