/*
	Imagesprite class that is a subclass of the basesprite class.
	This class draws and stores bitmap images.

	Author: Mikael Hallgren 2013
*/

#ifndef IMAGESPRITE_H
#define IMAGESPRITE_H

#include "Sprites.h"
#include "Image.h"

namespace Engine
{
	namespace Sprite
	{
		class ImageSprite: public Sprite
		{
		private:
			Graphics::Image m_spriteImage;

		public:
			ImageSprite();
			ImageSprite(char* filename);					// Constructor that creates an Graphics::Image-object
			ImageSprite(Graphics::Image & other);	// Constructor that stores a pointer to a Graphics::Image-object
			~ImageSprite();

			SDL_Surface * GetSurface();
		};
	}
}

#endif