#pragma once
class Target
{
public:
	Target();
	~Target();

	virtual void render(HDC hdc);
	virtual void tick();
	virtual void setX(int newX);
	virtual void setY(int newY);
	virtual POINT* getPoints();
	virtual int getNumPoints();
	virtual void hit(int strength);
	bool isAlive();
protected:
	int x, y, health, numPoints;
	float scale;
	bool alive;
private:
	HBRUSH targetBrush;
	POINT points[4];
};

