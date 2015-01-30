#pragma once
class Star
{
public:
	Star(int newX, int newY, float newScale);
	~Star();

	int x, y;
	float scale;

	void render(HDC hdc);
	void setX(int newX);
	void setY(int newY);
	void setScale(float newScale);
	void moveDown(int windowHeight);
};

