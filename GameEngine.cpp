#include "GameEngine.h"

namespace Engine
{
	GameEngine::GameEngine()
	{
		SDL_Init( SDL_INIT_EVERYTHING );
		TTF_Init();
		Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );

		this->m_gameScreen = new Graphics::Screen();
		this->m_spriteQueue = new Array<Sprite::Sprite>();
		this->m_gameObjects = new GameObjects();
		this->SetFPS(24);
	};

	GameEngine::~GameEngine()
	{
		delete this->m_spriteQueue;
		delete this->m_gameObjects;
		delete this->m_gameScreen;
		TTF_Quit();
		Mix_CloseAudio();
	};


	/*
		Private methods that are used in the mainloop of the GameEngine
	*/
	void GameEngine::KeyEventListener()
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT: 
				this->m_gameIsRunning = false; break;

			case SDL_KEYUP:
				for(int i = 0; i < 500; i ++)
				{
					if(event.key.keysym.sym == i)
						this->m_keyListener.SetState(i, false);
				}
				break;

			case SDL_KEYDOWN:
				for(int i = 0; i < 500; i ++)
				{
					if(event.key.keysym.sym == i)
						this->m_keyListener.SetState(i, true);
				}
				break;
			}
		}
	};

	void GameEngine::Draw()
	{
		if(this->m_gameScreen->GetScreen() != NULL){
			
			SDL_FillRect(this->m_gameScreen->GetScreen(), NULL, this->m_gameScreen->GetBackgroundColor());
			this->BackdropDraw();
			
			for(int i = 0; i < this->m_spriteQueue->Size(); i ++)
			{
				if(m_spriteQueue->Get(i)->GetShouldBeDrawn() == true)
				{
					SDL_BlitSurface(this->m_spriteQueue->Get(i)->GetSurface(),
						this->m_spriteQueue->Get(i)->GetSprite(),
						this->m_gameScreen->GetScreen(),
						this->m_spriteQueue->Get(i)->GetDrawCoordinates());
				}
			}

			SDL_Flip(this->m_gameScreen->GetScreen());
		}
	};
	

	/*
		Virtual GameEngine methods that are used
		during a game implementation
	*/
	void GameEngine::Load()
	{
		
	};

	void GameEngine::Update()
	{
		this->m_gameObjects->Update();
	};

	void GameEngine::BackdropDraw()
	{
	};
	
	
	/*
		Public method that are used to run gameengine
	*/
	void GameEngine::Run()
	{
		this->m_gameIsRunning = true;
		this->Load();
		this->Draw();	

		this->m_gameClock = 0;
		int long unsigned localTickCount = 0;

		while(this->m_gameIsRunning)
		{
			this->m_tickCounter.Start();
			
			this->KeyEventListener();
			this->Update();
			this->Draw();	
			
			this->m_tickCounter.Stop();

			if((this->m_tickCounter.GetTicks()) < (this->m_fpsTimer))
				SDL_Delay(this->m_fpsTimer - this->m_tickCounter.GetTicks());
			
			
			if(localTickCount == this->m_fpsTimer)
			{
				this->m_gameClock++;
				localTickCount =0;
			}
			else
				localTickCount++;

		}
	};


	/*
		GameEngine structures that are used 
		during a game implementation
	*/
	GameObjects * GameEngine::GetGameObjects()
	{
		return this->m_gameObjects;
	};

	Array<Sprite::Sprite>* GameEngine::GetSpriteQueue()
	{
		return this->m_spriteQueue;
	};
	
	Graphics::Screen* GameEngine::GetScreen()
	{
		return this->m_gameScreen;
	};
	
	int const GameEngine::GetGameTime()
	{
		return this->m_gameClock;
	}

	void GameEngine::ResetGameTime()
	{
		this->m_gameClock = 0;
	}
	
	void GameEngine::SetFPS(int unsigned in_fps)
	{
		this->m_fpsTimer = 1000 / in_fps;
	};
}