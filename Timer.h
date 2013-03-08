/*
	Timer-class that is used in the mainloop to be able 
	to regulate how many updates per second is being preformed.

	Author: Mikael Hallgren, 2013
*/

#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

namespace Engine
{
	class Timer
	{
	private:
		Uint32 m_startTick;
		Uint32 m_stopTick;

	public:
		void Start();		// Set m_startTick to the curren value of programs runtimeclock(SDL) in milliseconds
		void Stop();		// Set m_stopTick to the curren value of programs runtimeclock(SDL) in milliseconds
		int GetTicks(); // Returns the timedifferens between Start and Stop of timer.
	};
}

#endif