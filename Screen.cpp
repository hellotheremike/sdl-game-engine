#include "Screen.h"

namespace Engine
{
	namespace Graphics
	{
		Screen::Screen()
		{
			this->m_screen = NULL;
			this->m_screenTitle = NULL;
			this->m_screenWidth = 800;
			this->m_screenHeight = 600;
			this->m_screenBitDepth = 32;
			this->m_backgrond = 0xCCFF33;
		};

		Screen::~Screen()
		{
			if(this->m_screen != NULL)
				SDL_FreeSurface(this->m_screen);
		};

		int Screen::GetWidth()
		{
			return this->m_screenWidth;
		};

		int Screen::GetHeight()
		{
			return this->m_screenHeight;
		};
		
		SDL_Surface* Screen::GetScreen()
		{
			return this->m_screen;
		};
	
		void Screen::SetSize(int x, int y)
		{
			this->m_screenHeight = y;
			this->m_screenWidth = x;
		};

		void Screen::SetDepth(int in_bitDepth)
		{
			this->m_screenBitDepth = in_bitDepth;
		};
	
		void Screen::SetTitle(char* in_title)
		{
			this->m_screenTitle = in_title;
		};
	
		void Screen::SetBackgroundColor(Uint32 in_backgroundColor)
		{
			this->m_backgrond = in_backgroundColor;
		};

		Uint32 Screen::GetBackgroundColor()
		{
			return this->m_backgrond;
		};

		void Screen::ApplySettings()
		{
			this->m_screen = SDL_SetVideoMode( this->m_screenWidth , this->m_screenHeight, this->m_screenBitDepth , SDL_HWSURFACE | SDL_DOUBLEBUF); 
			if(this->m_screenTitle != NULL)
				SDL_WM_SetCaption(this->m_screenTitle , NULL);
		};
	}
}