#include "stdafx.h"

void initShotMananger();
void tickShotMananger(int shipX, int shipY);
void renderShots(HDC hdc);
void fire();
void reclaimShot(int id);
POINT* getShotPoints(int id);
int getShots();
int getStrenght();
bool isFired(int id);