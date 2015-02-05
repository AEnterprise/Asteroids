#pragma once
class SpaceShip
{
public:
	SpaceShip();
	~SpaceShip();

	int x, y;

	void render(HDC hdc);
	void tick();
	void moveToMouse(int mouseX, int mouseY);
};

