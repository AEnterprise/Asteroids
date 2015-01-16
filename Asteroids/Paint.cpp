#include "stdafx.h"

void generatePoints(POINT array[], int coordinates[], int amount);

void paint(HDC hdc) {
	
	
	SpaceShip ship;
	ship.render(hdc);

	Star star;
	star.render(hdc);
}