#pragma once
class Star
{
public:
	Star();
	~Star();

	int x, y;
	float scale;

	void render(HDC hdc);
};

