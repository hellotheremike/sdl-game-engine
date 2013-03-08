#include "Backdrop.h"

namespace Engine
{
	namespace Graphics
	{
		Backdrop::Backdrop()
		{

			this->m_height = 0;
			this->m_width =  0;
			
			this->m_ySprites = 0;
			this->m_ySaemline = 0;
			this->m_y = 0;
			
			this->m_xSprites = 0;
			this->m_xSaemline = 0;
			this->m_x = 0;
			
			this->m_speed = 0;

			this->draw = false;
		};

		Backdrop::Backdrop(char* filename):m_background(filename)
		{
			this->LoadBackdrop(filename);
		};
	
		Backdrop::~Backdrop()
		{
		};

		void Backdrop::LoadBackdrop(char * filename)
		{
			
			this->m_height = this->m_background.GetImage()->h;
			this->m_width =  this->m_background.GetImage()->w;
			
			this->m_ySprites = 3;
			this->m_ySaemline = (this->m_height/this->m_ySprites)*2-((this->m_height/this->m_ySprites)/2);
			this->m_y = 0;
			
			this->m_xSprites = 3;
			this->m_xSaemline = (this->m_width/this->m_xSprites)*2-((this->m_width/this->m_xSprites)/2);
			this->m_x = 0;
			
			this->m_speed = 2;
			this->draw = true;
			
		};

		void Backdrop::Draw(Screen * screen)
		{
			if(draw){
				this->m_offset.y = m_y;
				m_y += this->m_speed;
				if( m_y >= 0 )
					m_y = -this->m_ySaemline;

				SDL_BlitSurface(this->m_background.GetImage(),NULL,screen->GetScreen(), &this->m_offset);
			}
		};

		void Backdrop::SetScrollSpeed(int speed)
		{
			this->m_speed = speed;
		};

		void Backdrop::SetNumberOfSprites(int x, int y)
		{
			this->m_xSprites = x;
			this->m_ySprites = y;
		};
		
		void Backdrop::SetStartPosition(int x, int y)
		{
			this->m_x = x;
			this->m_y = y;
		};
	}
}