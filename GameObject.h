#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Sprites.h"
#include "FontSprite.h"
#include "Coordinate.h"
#include "Image.h"
#include <math.h>

namespace Engine
{
		class GameEngine;
		class ImageSprite;
		class GameObject
		{
		private:
			bool							m_removeObjectFlag;
			int	long unsigned	m_tickCounter;

		protected:
			char*						m_objectType;
			GameEngine*			m_engine;
			Sprite::Sprite*	m_sprite;
			GameObject*			m_collidingObject;

			Coordinate m_objectPosition;
			Coordinate m_objectOffset;

			Coordinate			m_movementCalculated;
			double					m_movementSpeed;
			double					m_movementAngle;


		public:
			GameObject();
			~GameObject();
			GameObject(GameEngine * in_engine,  char * in_image);
			GameObject(GameEngine * in_engine,  Graphics::Image& in_image);
			void Create(GameEngine * in_engine);
			Sprite::Sprite * GetSprite();
			void SetStartCoordinate(Coordinate tmp_startPosition);

			void Dispose();
			void Remove();
			bool RemoveFlag();
			void Update();
			
			virtual void DoOnCollision();
			void CheckForCollision(GameObject * other);
		
			void SetSpeed(double tmp_speed);
			void SetAngle(double tmp_angle);

			char* GetObjectType();
			int		GetTicksLived();
		};

}

#endif