#include "KeyListener.h"

namespace Engine
{
	KeyListener::KeyListener(void)
	{
		// Set every keystate to false
		for(int i = 0; i < 500; i ++)
		{
			this->m_keyState[i] = false;
		}
	}

	KeyListener::~KeyListener(void)
	{
	}

	void KeyListener::SetState(int in_index, bool in_value)
	{
		this->m_keyState[in_index] = in_value;
	}

	bool KeyListener::operator[](int in_index)
	{
		return this->m_keyState[in_index];
	}
}