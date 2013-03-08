#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Array.h"
#include "Timer.h"
#include "Screen.h"
#include "KeyListener.h"

#include "GameObjects.h"
#include "GameObject.h"

#include "Image.h"
#include "Backdrop.h"
#include "Sprites.h"
#include "ImageSprite.h"
#include "FontSprite.h"

namespace Engine
{
	class GameEngine
	{
	private:
		bool					m_gameIsRunning;	// Keeps the mainloop going. On quit this i set to false and breaks mainloop
		int	unsigned	m_fpsTimer;				// Frames-Per-Second flag
		int						m_gameClock;			// Keeps track on the how many seconds the game has lived
		
		void KeyEventListener();		// Function that loops over the KeyListener instance
		void Draw();								// Function that draws the queue of sprites added to the m_spriteQueue Array

		Timer										m_tickCounter;	// Determines how many milliseconds it takes for a loop in the mainloop, works as controller for the FPS
		GameObjects*						m_gameObjects;	// An Array inplementaton that holds all gameobjects that are initiated
		Array<Sprite::Sprite>*	m_spriteQueue;	// An Array inplementaton that holds all sprites that going to be drawn
		Graphics::Screen*				m_gameScreen;		// The mainscreen


	protected:
		void				 SetFPS(int unsigned fps);	// The ability to set the FPS in a gameimplementation
		virtual void Load();										// Loading and initiating resources
		virtual void Update();									// Updating gameobjects data 
		virtual void BackdropDraw();						// Ability to draw multiple or none backdrops
		KeyListener	 m_keyListener;							// Keylistener, that is used as a component to invoke events on a specific keypress


	public:
		void Run();							// Loadingresources, running mainloop and running updatemethods, used to start the game
		GameEngine();						// Constructor that initiates all necessary components
		virtual ~GameEngine();	// Virtual destructor that removes screen, sprites & gameobjects
		
		GameObjects*						GetGameObjects();	// Returns a pointer to m_gameObjects
		Array<Sprite::Sprite>*	GetSpriteQueue();	// Returns a pointer to m_spriteQueue
		Graphics::Screen*				GetScreen();			// Returns a pointer to m_gameScreen
		int const								GetGameTime();		// Returns the value of m_gameClock
		void										ResetGameTime();	// Sets gameclock to zero
	};
}
#endif