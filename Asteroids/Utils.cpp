#include "stdafx.h"

void movePoints(POINT array[], int xOffset, int yOffset, int amount){
	for (int t = 0; t < amount; t++) {
		array[t].x += xOffset;
		array[t].y += yOffset;
	}
}