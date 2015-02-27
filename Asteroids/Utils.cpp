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

bool hitTest(POINT array1[], int aantal1, POINT array2[], int aantal2){
	RECT obj1, obj2;
	obj1.left = array1[0].x;
	obj1.right = array1[0].x;
	obj1.top = array1[0].y;
	obj1.bottom = array1[0].y;
	for (int t = 1; t < aantal1; t++) {
		obj1.left = min(obj1.left, array1[t].x);
		obj1.right = max(obj1.right, array1[t].x);
		obj1.top = min(obj1.top, array1[t].y);
		obj1.bottom = max(obj1.bottom, array1[t].y);
	}
	obj2.left = array2[0].x;
	obj2.right = array2[0].x;
	obj2.top = array2[0].y;
	obj2.bottom = array2[0].y;
	for (int t = 1; t < aantal2; t++) {
		obj2.left = min(obj2.left, array2[t].x);
		obj2.right = max(obj2.right, array2[t].x);
		obj2.top = min(obj2.top, array2[t].y);
		obj2.bottom = max(obj2.bottom, array2[t].y);
	}

	return (obj1.top < obj2.bottom && obj1.bottom > obj2.top) && (obj1.right > obj2.left && obj1.left < obj2.right);
}
