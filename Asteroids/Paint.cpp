#include "stdafx.h"

SpaceShip ship;
Star star;

void paint(HDC hdc) {	
	ship.render(hdc);
	star.render(hdc);
}