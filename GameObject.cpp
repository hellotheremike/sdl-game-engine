#include "GameObject.h"
#include "GameEngine.h"
#include "Sprites.h"

#define PI 3.14159265

namespace Engine
{

	GameObject::GameObject()
	{
		this->m_objectType = "GameObject";
		this->m_removeObjectFlag = false;
		this->m_engine = NULL;
		this->m_sprite = NULL;
	};

	GameObject::GameObject(GameEngine * in_engine,  Graphics::Image & in_image)
	{
		this->m_sprite = new Sprite::ImageSprite(in_image);
		this->Create(in_engine);
	};

	GameObject::GameObject(GameEngine * in_engine, char * in_image)
	{
		this->m_sprite = new Sprite::ImageSprite(in_image);
		this->Create(in_engine);
	};

	GameObject::~GameObject()
	{
	};

	void GameObject::Update()
	{
		this->m_objectPosition = this->m_objectPosition + this->m_movementCalculated;
		this->m_sprite->Position = this->m_objectPosition;
		
		int tmp_imageHeight = this->GetSprite()->GetSurface()->h;
		int tmp_imageWidth	= this->GetSprite()->GetSurface()->h;

		this->m_tickCounter++;

		if(this->m_objectPosition.X < -tmp_imageWidth || 
			 this->m_objectPosition.X > (this->m_engine->GetScreen()->GetWidth() + tmp_imageWidth)|| 
			 this->m_objectPosition.Y < -tmp_imageHeight || 
			 this->m_objectPosition.Y > (this->m_engine->GetScreen()->GetHeight()+ tmp_imageHeight)
			)
			{
				this->Remove();
			}
	};

	void GameObject::CheckForCollision(GameObject * other)
	{
		this->m_collidingObject = other;
		if(other != this)
		{
			int leftA, leftB;
			int rightA, rightB;
			int topA, topB;
			int bottomA, bottomB;
			//Calculate the sides of rect A
		
			leftA = this->m_sprite->GetDrawCoordinates()->x;
			rightA = this->m_sprite->GetDrawCoordinates()->x + this->m_sprite->GetDrawCoordinates()->w;
			topA = this->m_sprite->GetDrawCoordinates()->y;
			bottomA = this->m_sprite->GetDrawCoordinates()->y + this->m_sprite->GetDrawCoordinates()->h;
        
			//Calculate the sides of rect B
			leftB = other->GetSprite()->GetDrawCoordinates()->x;
			rightB = other->GetSprite()->GetDrawCoordinates()->x + other->GetSprite()->GetDrawCoordinates()->w;
			topB = other->GetSprite()->GetDrawCoordinates()->y;
			bottomB = other->GetSprite()->GetDrawCoordinates()->y + other->GetSprite()->GetDrawCoordinates()->h;
		
			if((( bottomA <= topB) || (topA >= bottomB) || (rightA <= leftB) || (leftA >= rightB)) == false)
			{
				this->DoOnCollision();
			}
		}
	};

	void GameObject::DoOnCollision()
	{
		//this->Remove();
	};

	void GameObject::Create(GameEngine * in_engine)
	{
		this->m_movementAngle = 0;
		this->m_movementSpeed = 0;
		this->m_tickCounter		=	0;

		this->m_removeObjectFlag = false;
		this->m_engine = in_engine;
		this->m_sprite->Position = this->m_objectPosition + this->m_objectOffset;

		this->m_engine->GetSpriteQueue()->Add(this->m_sprite);
		this->m_engine->GetGameObjects()->Add(this);
	};


	void GameObject::Dispose()
	{
		this->m_engine->GetSpriteQueue()->Remove(this->m_sprite);
		this->m_engine->GetGameObjects()->Remove(this);
	}

	Sprite::Sprite * GameObject::GetSprite()
	{
		return this->m_sprite;
	}

	void GameObject::Remove()
	{
		this->m_removeObjectFlag = true;
	}

	bool GameObject::RemoveFlag()
	{
		return this->m_removeObjectFlag;
	}

	char*GameObject::GetObjectType()
	{
		return this->m_objectType;
	}
	
	void GameObject::SetSpeed(double tmp_speed)
	{
		this->m_movementSpeed = tmp_speed;
		this->m_movementCalculated.X = cos(this->m_movementAngle*PI/180) * this->m_movementSpeed;
		this->m_movementCalculated.Y = sin(this->m_movementAngle*PI/180) * this->m_movementSpeed;
	};

	void GameObject::SetAngle(double tmp_angle)
	{
		this->m_movementAngle = -tmp_angle- 90.0;
		this->m_movementCalculated.X = cos(this->m_movementAngle*PI/180) * this->m_movementSpeed;
		this->m_movementCalculated.Y = sin(this->m_movementAngle*PI/180) * this->m_movementSpeed;
	}

	void GameObject::SetStartCoordinate(Coordinate startPosition)
	{
		this->m_objectPosition = this->m_objectOffset + startPosition;
		this->m_sprite->Position = this->m_objectPosition;
	};

	int	 GameObject::GetTicksLived()
	{
		return this->m_tickCounter;
	}
}