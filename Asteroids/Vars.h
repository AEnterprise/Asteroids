#pragma once
class Vars{
public:
	static const int NUMSHOTS = 5;
	static const int NUMSTARS = 60;
	static const int NUMTARGETS = 1;

	static LaserShot* shots[NUMSHOTS];
	static bool fired[NUMSHOTS];
	static SpaceShip* ship;
	static Star* star[NUMSTARS];
	static Target* targets[NUMTARGETS];
};