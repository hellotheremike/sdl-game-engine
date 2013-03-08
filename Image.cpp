#include "Image.h"
#include <SDL_image.h>

namespace Engine
{
	namespace Graphics
	{
		Image::Image()
		{
		};

		Image::Image(char* filename)
		{
			this->LoadImage(filename);
		};

		Image::Image(const Image & origin)
		{
			this->m_imageSurface = origin.m_imageSurface;
			this->m_imageSurface->refcount++;
		};

		Image::~Image()
		{
			if(this->m_imageSurface != NULL)
				SDL_FreeSurface(this->m_imageSurface);
		};

		void Image::LoadImage(char* filename)
		{
			SDL_Surface* loadedImage = NULL;
			SDL_Surface* optimizedImage = NULL;

			// Loads image
			loadedImage = IMG_Load(filename);
			if( loadedImage != NULL )
			{
				optimizedImage = SDL_DisplayFormat( loadedImage );
				SDL_FreeSurface( loadedImage );

				// If image optemized colorkey image with color magenta to be transparent  
				if( optimizedImage != NULL )
				{
					SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, 0xFF00FF );
				}

				this->m_imageSurface = optimizedImage;
			}
		};

		SDL_Surface * Image::GetImage()
		{
			return this->m_imageSurface;
		};

		const Image& Image::operator=(const Image& origin)
		{
			if(this != &origin)
			{
				// Remove the old object
				SDL_FreeSurface(this->m_imageSurface);

				// Copy the poiner to the new image and add to its counter
				this->m_imageSurface = origin.m_imageSurface;
				this->m_imageSurface->refcount ++;
			}
			
			return *this;
		};
	}
}