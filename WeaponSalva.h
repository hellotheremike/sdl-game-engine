#ifndef WEAPONSALVA_H
#define WEAPONSALVA_H

#include "GameEngine.h"
#include "Image.h"
#include "Coordinate.h"
using namespace Engine;
class WeaponSalva: public GameObject
{
public:
	WeaponSalva(GameEngine * in_engine, Graphics::Image & in_salvaImage, double in_speed, double in_angle, Coordinate in_offset, Coordinate in_startPosition);
	~WeaponSalva();
	void DoOnCollision();
};
#endif