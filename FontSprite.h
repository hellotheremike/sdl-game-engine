/*
	Fontsprite class that is a subclass of the basesprite-class.
	This class draws and stores text with TrueTypeFont.

	Author: Mikael Hallgren 2013
*/

#ifndef FONTSPRITE_H
#define FONTSPRITE_H

#include "Sprites.h"
#include <SDL_ttf.h>

namespace Engine
{
	namespace Sprite
	{
		class FontSprite: public Sprite
		{
		private:
			char * m_text;							// Stores the text that should be drawn
			TTF_Font * m_font;					// Stores the font that will be used when drawing
			SDL_Surface* m_fontSurface; // Surface to draw
			SDL_Color m_color;					// Stores the color that the text will use

		public:
			FontSprite();
			FontSprite(char* tmp_text, TTF_Font * font);
			FontSprite(char* tmp_text, TTF_Font * font, SDL_Color &tmp_color);
			~FontSprite();

			SDL_Surface* GetSurface();
			void				 SetText(char * tmp_text);
			char *			 GetText();
		};
	}
}

#endif