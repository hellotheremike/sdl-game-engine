#include "Sprites.h"

namespace Engine
{
	namespace Sprite
	{
		Sprite::Sprite()
		{
			this->m_sprites = NULL;
			this->m_drawThisSprite = true;
		};

		Sprite::~Sprite()
		{
		};

		SDL_Rect * Sprite::GetDrawCoordinates()
		{
			this->m_coordinates.x = this->Position.X;
			this->m_coordinates.y = this->Position.Y;
			return &this->m_coordinates;
		};

		SDL_Rect * Sprite::GetSprite()
		{
			return this->m_sprites;
		};

		SDL_Surface * Sprite::GetSurface()
		{
			return NULL;
		};

		void Sprite::SetShouldBeDrawn(bool tmp_SetDrawSprite)
		{
			this->m_drawThisSprite = tmp_SetDrawSprite;
		};

		bool Sprite::GetShouldBeDrawn()
		{
			return this->m_drawThisSprite;
		};
	}
}