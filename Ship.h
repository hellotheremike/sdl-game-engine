#ifndef SHIP_H
#define SHIP_H

#include "GameEngine.h"
using namespace Engine;

namespace Ship 
{
	class Ship : public GameObject
	{
	protected:
		int m_healthMax;
		int m_healthCurrent;
		int m_velocity;
		Graphics::Image m_ship;

	public:
		Ship();
		virtual ~Ship();
		Ship(GameEngine * in_engine, char * filename,					Coordinate start);
		Ship(GameEngine * in_engine, Graphics::Image & image, Coordinate start);

		void SetHealth(int health);
		int	 GetHealth();
		void AddHealth(int health);
		void SetMaxHealth(int health);
		void DoOnCollision();
	};
}

#endif