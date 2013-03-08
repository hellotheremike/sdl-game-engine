#ifndef WEAPON_H
#define WEAPON_H

#include "GameEngine.h"
using namespace Engine;

class Weapon
{
private:
	Graphics::Image weaponSprite;
	GameEngine * engine;
	double speed;


public:
	Weapon(GameEngine * engine, Graphics::Image & weaponImage, double speed);
	~Weapon();
	void Fire(Coordinate startPosition);
};
#endif