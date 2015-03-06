#include "stdafx.h"

void initShotMananger() {
	for (int t = 0; t < Vars::NUMSHOTS; t++) {
		Vars::shots[t] = new LaserShot(t);
		Vars::fired[t] = false;
	}
}

void tickShotMananger(int shipX, int shipY){
	for (int t = 0; t < Vars::NUMSHOTS; t++)
		Vars::shots[t]->tick(shipX, shipY);
}

void renderShots(HDC hdc){
	for (int t = 0; t < Vars::NUMSHOTS; t++)
		Vars::shots[t]->render(hdc);
}

void fire(){
	for (int t = 0; t < Vars::NUMSHOTS; t++) {
		if (!Vars::fired[t]) {
			Vars::shots[t]->launch();
			Vars::fired[t] = true;
			return;
		}
	}
}

void reclaimShot(int id){
	Vars::fired[id] = false;
	Vars::shots[id]->hit();
}
