/*
	Class that holds an array of gameObjects,
	that has an update function that runs in the main gameloop.

	This makes it possible to update the position of a gameobject and 
	determine speed/angle of an object.

	This also makes is possible to create gameobjects that can 
	detect collision based on the position of other objects in the m_gameObjects Array.

	Every gameobject handles their own event on collision.

	Author: Mikael Hallgren 2013
*/

#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "Array.h"
#include "GameObject.h"

namespace Engine
{
	class GameObjects
	{
	private:
		Array<GameObject> * m_gameObjects;		// Array that holds all the games GameObjects

	public:
		GameObjects();
		~GameObjects();
		void Remove(GameObject * in_object);	// Remove a given GameObject, for instance when its out of the screen
		void Add(GameObject * in_object);			// Add a new GameObject to the m_gameObjects list, to make it possible to update its possition
		void Update();												// Update function that runs in mainloop
		int	 Size();													// Returns number of gameobjects
	};
}

#endif