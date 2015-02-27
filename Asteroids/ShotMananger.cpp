#include "stdafx.h"

const int NUMSHOTS = 5;

LaserShot* shots[NUMSHOTS];
bool fired[NUMSHOTS];
int strength = 1;

void initShotMananger() {
	for (int t = 0; t < NUMSHOTS; t++) {
		shots[t] = new LaserShot(t);
		fired[t] = false;
	}
}

void tickShotMananger(int shipX, int shipY){
	for (int t = 0; t < NUMSHOTS; t++)
		shots[t]->tick(shipX, shipY);
}

void renderShots(HDC hdc){
	for (int t = 0; t < NUMSHOTS; t++)
		shots[t]->render(hdc);
}

void fire(){
	for (int t = 0; t < NUMSHOTS; t++) {
		if (!fired[t]) {
			shots[t]->launch();
			fired[t] = true;
			return;
		}
	}
}

void reclaimShot(int id){
	fired[id] = false;
	shots[id]->hit();
}


POINT* getShotPoints(int id){
	return shots[id]->getPoints();
}

int getShots(){
	return NUMSHOTS;
}

int getStrenght(){
	return strength;
}

bool isFired(int id) {
	return fired[id];
}