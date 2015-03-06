#pragma once
class LaserShot
{
public:
	LaserShot(int id);
	~LaserShot();
	
	void render(HDC hdc);
	void launch();
	void tick(int shipX, int shipY);
	void setX(int newX);
	void setY(int newY);
	POINT* getPoints();
	void hit();
	int getStrength();

private:
	int shotX, shotY, id, strength;
	bool flying;
	POINT laserPoints[4], laserPoints2[4];
};

