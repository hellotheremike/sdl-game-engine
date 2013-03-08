/*
	Screen class that wrapps the screeninitation
	and setting in getters and setter to give a clean interface.

	Author: Mikael Hallgren, 2013
*/

#ifndef SCREEN_H
#define SCREEN_H
#include <SDL.h>

namespace Engine
{
	namespace Graphics
	{
		class Screen
		{
		private:
			SDL_Surface *m_screen;	// Game main screen surface
			char * m_screenTitle;		// Game title
			int m_screenWidth;			// Game screen width
			int m_screenHeight;			// Game screen heigh
			int m_screenBitDepth;		// Game screen bitdepth
			Uint32 m_backgrond;			// Game screen background color
			

		public:
			Screen(void);
			~Screen(void);
			void ApplySettings();	// Initiates screen with its settings

			int GetWidth();		
			int GetHeight();
			
			void SetSize(int x, int y);
			void SetDepth(int in_bitDepth);
			void SetTitle(char* in_title);	
			void SetBackgroundColor(Uint32 in_backgroundColor);

			SDL_Surface* GetScreen();
			Uint32 GetBackgroundColor();
		};
	}
}
#endif