#include "GameObjects.h"

namespace Engine
{
	GameObjects::GameObjects()
	{
		this->m_gameObjects = new Array<GameObject>();
	}

	GameObjects::~GameObjects()
	{
		delete this->m_gameObjects;
	}

	// Add new GameObject to GameObjects list
	void GameObjects::Add(GameObject * object)
	{
		this->m_gameObjects->Add(object);
	}

	// Remove specific GameObject from GameObjects list
	void GameObjects::Remove(GameObject * object)
	{
		this->m_gameObjects->Remove(object);
	}

	// Function that runs in main gameloop 
	void GameObjects::Update()
	{
		for (int x = 0; x < this->m_gameObjects->Size();	x++)
		{
			// Check if object is colliding with other GameObjects
			for (int y = 0; y < this->m_gameObjects->Size();	y++)
			{
				this->m_gameObjects->Get(x)->CheckForCollision(this->m_gameObjects->Get(y));
			}

			// Run update function that updates position the position Gameobjects
			this->m_gameObjects->Get(x)->Update();
		}

		// Remove objects that have colided or gone out of the screen
		for (int i = 0; i < this->m_gameObjects->Size();	i++)
		{
			if(this->m_gameObjects->Get(i)->RemoveFlag())
				this->m_gameObjects->Get(i)->Dispose();
		}
	}

	int GameObjects::Size()
	{
		return this->m_gameObjects->Size();
	}
}