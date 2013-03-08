#include "Ship.h"
namespace Ship 
{
	Ship::Ship()
	{
	};

	Ship::Ship(GameEngine * in_engine, char * filename,  Coordinate start)
	{
		this->m_objectType = "Ship";
		this->m_engine = in_engine;
		this->m_objectPosition = start;
		this->m_sprite = new Sprite::ImageSprite(filename);
		this->Create(this->m_engine);
	};

	Ship::Ship(GameEngine * in_engine, Graphics::Image & image, Coordinate start)
	{
		this->m_objectType = "Ship";
		this->m_engine = in_engine;
		this->m_objectPosition = start;
		this->m_sprite = new Sprite::ImageSprite(image);
		this->Create(this->m_engine);
	};
	
	Ship::~Ship()
	{
	};
	

	void Ship::SetHealth(int health)
	{
		this->m_healthCurrent = health;
	};

	int Ship::GetHealth()
	{
		return this->m_healthCurrent;
	};

	
	void Ship::AddHealth(int health)
	{
		this->m_healthCurrent += health;
	};

	void Ship::SetMaxHealth(int health)
	{
		this->m_healthMax = health;
	};

	
	void Ship::DoOnCollision()
	{
		if(this->m_collidingObject->GetObjectType() == "WeaponSalva" || this->m_collidingObject->GetObjectType() == "ShipPlayer")
		{
			this->Remove();
		}
	};
}