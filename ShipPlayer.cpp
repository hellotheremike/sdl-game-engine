#include "ShipPlayer.h"
#include "Weapon.h"

namespace Ship 
{
	ShipPlayer::ShipPlayer()
	{
		this->m_engine = NULL;
		this->m_weapon = NULL;
	}

	ShipPlayer::ShipPlayer(GameEngine * in_engine, char * filename, Weapon * weapon, Coordinate startPosition)
	{
		this->m_objectType = "ShipPlayer";
		this->m_sprite = new Sprite::ImageSprite(filename);
		this->m_velocity = 3;
		this->m_healthCurrent = 5;
		this->m_weapon = weapon;
		this->m_objectPosition = startPosition;
		this->m_currentSpeed.SetCoordinate(1,1);
		this->m_lastTick = 0;

		this->Create(in_engine);
	}

	ShipPlayer::ShipPlayer(GameEngine * in_engine, Graphics::Image & image, Weapon * weapon, Coordinate startPosition)
	{
		this->m_objectType = "ShipPlayer";
		this->m_sprite = new Sprite::ImageSprite(image);
		this->m_velocity = 3;
		this->m_healthCurrent = 5;
		this->m_weapon = weapon;
		this->m_objectPosition = startPosition;
		this->m_currentSpeed.SetCoordinate(1,1);
		this->Create(in_engine);
		this->m_lastTick = 0;
	}

	
	void ShipPlayer::Fire()
	{
		if(this->GetTicksLived() >= this->m_lastTick + 10)
		{
			this->m_lastTick = this->GetTicksLived();
			this->m_weapon->Fire(this->m_sprite->Position);
		}
	}

	void ShipPlayer::MoveUp()
	{
		if(this->m_objectPosition.Y > 0)
			this->m_objectPosition.Y -= 6;
	};

	void ShipPlayer::MoveDown()
	{
		if(this->m_objectPosition.Y < this->m_engine->GetScreen()->GetHeight()-130)
			this->m_objectPosition.Y += 6;
	};

	void ShipPlayer::MoveLeft()
	{
		if(this->m_objectPosition.X > 6)
			this->m_objectPosition.X -= 6;
	};

	void ShipPlayer::MoveRight()
	{
		if(this->m_objectPosition.X < this->m_engine->GetScreen()->GetWidth()-95)
			this->m_objectPosition.X += 6;
	};

	void ShipPlayer::MoveStop()
	{
	};

	void ShipPlayer::DoOnCollision()
	{
		if(this->m_collidingObject->GetObjectType() != "PlayerShip" && this->m_collidingObject->GetObjectType() != "WeaponSalva")
		{
			// imortal
		}
		if(this->m_healthCurrent == 0)
			this->m_sprite->SetShouldBeDrawn(false);
	}
}
