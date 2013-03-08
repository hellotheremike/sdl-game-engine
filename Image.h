/*
	Image class that loads images and stores them in a SDL_Surface.
	All Images are colorkeyed to have magenta as transparent(#FF00FF) color.

	Suports formats: BMP, GIF, JPEG, LBM, PCX, PNG, PNM, TGA, TIFF, WEBP, XCF, XPM and XV

	Author: Mikael Hallgren, 2013
*/

#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>

namespace Engine
{
	namespace Graphics
	{
		class Image
		{
		private:
			SDL_Surface* m_imageSurface;		// Surface where the image is stored and placed
			void LoadImage(char* filename);	// Helpfunction that loads and 
		
		public:
			Image();
			Image(char* filename);			// Creates new SDL_Surface instance and loads image
			Image(const Image & other);	// m_imageSurface points to the other image SDL_Surface, increases refcount.
			~Image();

			SDL_Surface * GetImage();		// Return m_imageSurface
			const Image & operator=(const Image & other);	// m_imageSurface points to the other image SDL_Surface, increases refcount.
		};
	}
}

#endif