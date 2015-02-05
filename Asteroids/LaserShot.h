#pragma once
class LaserShot
{
public:
	LaserShot(int id);
	~LaserShot();
	int shotX, shotY, id;
	bool flying;
	void render(HDC hdc);
	void launch();
	void tick(int shipX, int shipY);
};

