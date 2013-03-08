#ifndef SHIPPlayer_H
#define SHIPPlayer_H

#include "GameEngine.h"
#include "Ship.h"
using namespace Engine;

class Weapon;
namespace Ship 
{
	class ShipPlayer : public Ship
	{
	private:
		Coordinate m_currentSpeed;
		int m_lastTick;
	protected:
		Weapon*	m_weapon;
		int			m_shipVelocity;

	public:
		ShipPlayer();
		ShipPlayer(GameEngine * in_engine, char * filename, Weapon * weapon, Coordinate startPosition);
		ShipPlayer(GameEngine * in_engine, Graphics::Image & image, Weapon * weapon,  Coordinate startPosition);

		void Fire();
		void MoveUp();
		void MoveDown();
		void MoveLeft();
		void MoveRight();
		void MoveStop();
		void DoOnCollision();
	};
}

#endif