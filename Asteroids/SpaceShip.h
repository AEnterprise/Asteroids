#pragma once
class SpaceShip
{
public:
	SpaceShip();
	~SpaceShip();

	int x, y;
	bool up, down, left, right;

	void render(HDC hdc);
	void tick();
	void fire();
};

