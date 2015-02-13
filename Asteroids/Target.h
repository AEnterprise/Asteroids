#pragma once
class Target
{
public:
	Target();
	~Target();

	int x, y, health;
	float scale;

	void render(HDC hdc);
	void tick();
};

