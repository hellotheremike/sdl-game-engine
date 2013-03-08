#include "WeaponSalva.h"

WeaponSalva::WeaponSalva(GameEngine * in_engine, Graphics::Image & in_salvaImage, double in_speed, double in_angle, Coordinate in_offset, Coordinate in_startPosition)
{
	this->m_objectType = "WeaponSalva";
	this->m_sprite = new Sprite::ImageSprite(in_salvaImage);
	this->Create(in_engine);
	this->SetSpeed(in_speed);
	this->SetAngle(in_angle);
	this->m_objectOffset = in_offset;
	this->SetStartCoordinate(in_startPosition);
}

void WeaponSalva::DoOnCollision()
{
	if(this->m_collidingObject->GetObjectType() != "WeaponSalva" && this->m_collidingObject->GetObjectType() != "ShipPlayer")
	{
		this->Remove();
	}
};

WeaponSalva::~WeaponSalva()
{
}