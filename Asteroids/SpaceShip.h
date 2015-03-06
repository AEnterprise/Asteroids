#pragma once
class SpaceShip
{
public:
	SpaceShip();
	~SpaceShip();


	void render(HDC hdc);
	void tick();
	void moveToMouse(int mouseX, int mouseY, RECT rect);

private:
	int x, y;
	float scale;
};

