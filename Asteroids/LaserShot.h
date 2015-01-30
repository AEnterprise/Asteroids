#pragma once
class LaserShot
{
public:
	LaserShot();
	~LaserShot();
	int x, y;
	void render(HDC hdc);
	void launch();
	void tick(int shipX, int shipY);
};

