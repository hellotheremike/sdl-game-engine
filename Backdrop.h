#ifndef BACKDROP_H
#define BACKDROP_H

#include <SDL.h>
#include "Image.h"
#include "Screen.h"

namespace Engine
{
	namespace Graphics
	{
		class Backdrop
		{
		private:
			Image m_background;
			int m_speed;
			int m_height;
			int m_width;
			bool draw;

			int m_ySaemline;
			int m_ySprites;
			int m_xSaemline;
			int m_xSprites;

			SDL_Rect m_offset;
			int m_x;
			int m_y;

		public:
			Backdrop();
			Backdrop(char * filename);
			~Backdrop();
			void SetScrollSpeed(int speed);
			void LoadBackdrop(char* filename);
			void SetNumberOfSprites(int x, int y);
			void SetStartPosition(int x, int y);
			virtual void Draw(Screen * screen);
		};
	}
}

#endif