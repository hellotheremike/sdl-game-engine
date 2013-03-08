#include "FontSprite.h"

namespace Engine
{
	namespace Sprite
	{
		FontSprite::FontSprite()
		{
			this->m_color.r = 255;
			this->m_color.g = 255;
			this->m_color.b = 255;
			this->m_fontSurface = NULL;
			this->m_font = NULL;
			this->m_text = "";
		};
		
		FontSprite::FontSprite(char* text, TTF_Font * font)
		{
			this->m_color.r = 255;
			this->m_color.g = 255;
			this->m_color.b = 255;
			this->m_text = text;
			this->m_font = font;
			this->m_fontSurface = TTF_RenderText_Solid( this->m_font, this->m_text, this->m_color );
		};

		FontSprite::FontSprite(char* text, TTF_Font * font, SDL_Color &tmp_color)
		{
			this->m_color= tmp_color;
			this->m_font = font;
			this->m_fontSurface = TTF_RenderText_Solid( this->m_font, this->m_text, this->m_color );
		};

		FontSprite::~FontSprite()
		{
			delete [] this->m_text;
			delete this->m_fontSurface;
		};

		void FontSprite::SetText(char* text)
		{
			this->m_text = text;
			SDL_FreeSurface(this->m_fontSurface);
			this->m_fontSurface = TTF_RenderText_Solid( this->m_font, text, this->m_color );
		}
		
		char * FontSprite::GetText()
		{
			return this->m_text;
		}
		
		SDL_Surface* FontSprite::GetSurface()
		{
			return this->m_fontSurface;
		}
	}
}