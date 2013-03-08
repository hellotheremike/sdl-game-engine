#include "Weapon.h"
#include "WeaponSalva.h"

Weapon::Weapon(GameEngine * engine, Graphics::Image & weaponImage, double speed):weaponSprite(weaponImage)
{
	this->engine = engine;
	this->speed = speed;
};

Weapon::~Weapon()
{
};

void Weapon::Fire(Coordinate startPosition)
{		
	new WeaponSalva(this->engine, this->weaponSprite, this->speed, 8.0, Coordinate(43,10), startPosition);
	new WeaponSalva(this->engine, this->weaponSprite, this->speed, 0.0, Coordinate(43,10), startPosition);
	new WeaponSalva(this->engine, this->weaponSprite, this->speed, -8.0, Coordinate(43,10), startPosition);
};