#include "stdafx.h"

void movePoints(POINT array[], int xOffset, int yOffset, int amount){
	for (int t = 0; t < amount; t++) {
		array[t].x += xOffset;
		array[t].y += yOffset;
	}
}

void scalePoints(POINT array[], float scale, int amount) {
	for (int t = 0; t < amount; t++) {
		array[t].x = array[t].x * scale;
		array[t].y = array[t].y * scale;
	}
}