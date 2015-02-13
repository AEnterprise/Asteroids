#pragma once
class Star
{
public:
	Star(int newX, int newY, float newScale);
	~Star();

	void render(HDC hdc);
	void setX(int newX);
	void setY(int newY);
	void setScale(float newScale);
	void moveDown(int windowWith, int windowHeight);

private:
	int starX, starY;
	float scale;
};

