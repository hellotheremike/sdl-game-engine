#include "ImageSprite.h"

namespace Engine
{
	namespace Sprite
	{
		ImageSprite::ImageSprite()
		{
		};

		ImageSprite::ImageSprite(char * filename):m_spriteImage(filename)
		{
		};

		ImageSprite::ImageSprite(Graphics::Image & other):m_spriteImage(other)
		{
		};

		ImageSprite::~ImageSprite()
		{
		};

		SDL_Surface *  ImageSprite::GetSurface()
		{
			return this->m_spriteImage.GetImage();
		}
	}
}