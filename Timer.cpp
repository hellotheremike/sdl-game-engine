#include "Timer.h"

namespace Engine
{
	void Timer::Start()
	{
		this->m_startTick = SDL_GetTicks();
	};
	void Timer::Stop()
	{
		this->m_stopTick = SDL_GetTicks();
	};
	int Timer::GetTicks()
	{
		return this->m_stopTick - this->m_startTick;
	};
}