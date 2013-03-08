/*
	Base Sprite class that will be used to 
	hold objects to be drawn on the screen

	Author: Mikael Hallgren 2013
*/

#ifndef SPRITES_H
#define SPRITES_H

#include <SDL.h>
#include "Image.h"
#include "Coordinate.h"

namespace Engine
{
	namespace Sprite
	{
		class Sprite
		{
		private:
			bool m_drawThisSprite;		// Flag that determines if the sprite will be drawn or not

		protected:
			SDL_Rect	m_coordinates;	// Coordinates that SDL use to draw on surface
			SDL_Rect*	m_sprites;			// Posibility for object to have sprites ! NOT IMPLEMENTED !

		public:
			Sprite();
			~Sprite();

			Coordinate Position;								// The interface to the placement of the sprite
			SDL_Rect * GetDrawCoordinates();		// Returns m_Coordinates
			SDL_Rect * GetSprite();							// Returns m_sprite
 			virtual SDL_Surface * GetSurface();	// Returns m_surface, virtual to make it easy to extend class
			
			void SetShouldBeDrawn(bool tmp_DrawSprite);	// Sets m_drawThisSprite
			bool GetShouldBeDrawn();										// Returns m_drawThisSprite
		};
	}
}

#endif