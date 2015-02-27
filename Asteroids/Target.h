#pragma once
class Target
{
public:
	Target();
	~Target();

	void render(HDC hdc);
	void tick();
	void setX(int newX);
	void setY(int newY);
	POINT* getPoints();
	int getNumPoints();
	void hit(int strength);
	bool isAlive();
private:
	int x, y, health, numPoints;
	float scale;
	POINT points[4];
	bool alive;
};

