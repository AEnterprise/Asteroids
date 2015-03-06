#pragma once
#include "Target.h"
class Asteroid : public Target
{
public:
	Asteroid();
	~Asteroid();
	void render(HDC hdc);
	POINT* getPoints();
	int getNumPoints();
	void tick();
private:
	HBRUSH brush;
	POINT points[4];
};

