/*
	This keyclass will be used in the mainloop to work like
	a checker to invoke methods on keyevents.

	When a key is pushed down its SDL_Key index will be set to true in the m_keyState array.
	Then in the GameImplementation the program ju has to check if the Key[SDL_Key::KEY] is true 
	to be able to invoke action.

	Author: Mikael Hallgren 2013
*/

#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include <SDL.h>

namespace Engine
{
	class KeyListener
	{
	private:
		bool m_keyState[500];		// Array what hold keystates

	public:
		KeyListener();
		~KeyListener();

		void SetState(int in_index, bool in_state);		// Set Keystate at given index
		bool operator[](int in_index);								// Keystate at given index
	};
}

#endif