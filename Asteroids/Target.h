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
private:
	int x, y, health;
	float scale;
};

