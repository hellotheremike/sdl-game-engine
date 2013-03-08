#include "Game.h"

Game::Game()
{
};
void Game::Load()
{
	//Initiate screen before loading resources
	this->GetScreen()->SetTitle("Game Engine Running");
	this->GetScreen()->SetBackgroundColor(0x000000);
	this->GetScreen()->ApplySettings();

	this->fontBig  = TTF_OpenFont( "Resources/fonts/minecraft.ttf", 32 );
	this->fontSmal = TTF_OpenFont( "Resources/fonts/minecraft.ttf", 12 );

	this->backdrop = new Graphics::Backdrop("Resources/image/bg_2.bmp");
	this->backdrop->SetStartPosition(0,-350);

	this->secondBack = new Graphics::Backdrop("Resources/image/bg_overlay.bmp");
	this->secondBack->SetStartPosition(0,-350);
	this->secondBack->SetScrollSpeed(5);

	Graphics::Image playerIMG("Resources/image/milleniumFalconThrust.bmp");
	this->imp_enemyImage = new Graphics::Image("Resources/image/tiefighter.bmp");

	this->imp_countDown = false;
	this->imp_gameRunning = false;
	this->imp_playerDead = false;
	this->imp_waitingForPlayer = true;
	this->imp_bufferTimer = this->GetGameTime();

	this->bigCenterText = new Sprite::FontSprite("", fontBig);
	this->smallCenterText = new Sprite::FontSprite("", fontSmal);

	this->GetSpriteQueue()->Add(bigCenterText);
	this->GetSpriteQueue()->Add(smallCenterText);

	this->imp_player = new Ship::ShipPlayer(this, 
		playerIMG, 
		new Weapon(this, Graphics::Image("Resources/image/shot.bmp"),6.5), 
		Coordinate(0,0)
		);	
	imp_player->SetStartCoordinate(Coordinate((this->GetScreen()->GetWidth()/2)-(this->imp_player->GetSprite()->GetSurface()->w/2), (this->GetScreen()->GetHeight()/2)+40));

};

void Game::Update()
{
	GameEngine::Update();

	if(this->imp_gameRunning)
	{
		this->secondBack->SetScrollSpeed(5);

		if(this->m_keyListener[SDLK_UP])
		{
			this->imp_player->MoveUp();
			this->secondBack->SetScrollSpeed(7);
		}
		if(this->m_keyListener[SDLK_DOWN])
		{
			this->imp_player->MoveDown();
			this->secondBack->SetScrollSpeed(4);
		}
		if(this->m_keyListener[SDLK_LEFT])
		{
			this->imp_player->MoveLeft();
		}
		if(this->m_keyListener[SDLK_RIGHT])
		{
			this->imp_player->MoveRight();
		}
		if(this->m_keyListener[SDLK_SPACE])
		{
			this->imp_player->Fire();
		}

		if(!this->m_keyListener[SDLK_RIGHT] && this->m_keyListener[SDLK_LEFT] && this->m_keyListener[SDLK_DOWN] && this->m_keyListener[SDLK_UP])
		{
			this->imp_player->MoveStop();
		}

			this->generateBadGuys();
	}
	else if(this->imp_waitingForPlayer)
	{
		this->bigCenterText->SetText("Millenium falcon");
		this->smallCenterText->SetText("press space to begin");

		this->bigCenterText->Position = Coordinate((this->GetScreen()->GetWidth()/2)-(this->bigCenterText->GetSurface()->w/2),  (this->GetScreen()->GetHeight()/2)-(this->bigCenterText->GetSurface()->h/2)-40);
		this->smallCenterText->Position = Coordinate((this->GetScreen()->GetWidth()/2) - (this->smallCenterText->GetSurface()->w/2),  (this->GetScreen()->GetHeight()/2)-(this->smallCenterText->GetSurface()->h/2));

		if(this->m_keyListener[SDLK_SPACE])
		{
			this->bigCenterText->SetText("");
			this->smallCenterText->SetText("");
			this->imp_waitingForPlayer = false;
			this->imp_countDown = true;
			this->ResetGameTime();
			this->imp_bufferTimer = 3;
		}
	}
	else if(this->imp_countDown)
	{
		if(this->GetGameTime() <= 3)
		{
			int diff = this->imp_bufferTimer - this->GetGameTime();
			char buffer[6];
			itoa(diff, buffer, 6);
			if(diff == 0){
				this->bigCenterText->SetText("FIGHT!");
				this->generateBadGuys();
			}
			else
				this->bigCenterText->SetText(buffer);

			this->bigCenterText->Position = Coordinate((this->GetScreen()->GetWidth()/2) - (this->bigCenterText->GetSurface()->w/2),  (this->GetScreen()->GetHeight()/2)-(this->bigCenterText->GetSurface()->h/2));
		}
		else{
			this->bigCenterText->SetText("");
			this->imp_bufferTimer = 0;
			this->ResetGameTime();
			this->imp_gameRunning = true;
			this->imp_countDown = false;
		}
	}
};

void Game::BackdropDraw()
{
	this->backdrop->Draw(this->GetScreen());
	this->secondBack->Draw(this->GetScreen());
};

Game::~Game()
{
	/*
	Dont do ceanup on sprites and gameobjects.
	They are automatically cleanedup by the GameEngine's destructor.

	This by the destructor in the Array class that loops over
	itself and removes all within it.

	And because all GameObjects and Sprites have pointers to themslef 
	the Arrays in m_spriteQueue and m_worldObjects, they are automatically removed.

	*/

	delete this->backdrop;
	delete this->secondBack;
	TTF_CloseFont(this->fontBig);
	TTF_CloseFont(this->fontSmal);
};

void Game::generateBadGuys()
{
	if(this->GetGameObjects()->Size() < 2){
		imp_enemys = new Ship::Ship(this, *this->imp_enemyImage, Coordinate(0,0));
		imp_enemys->SetStartCoordinate(Coordinate(80,-imp_enemys->GetSprite()->GetSurface()->h));
		imp_enemys->SetAngle(4.0);
		imp_enemys->SetSpeed(-2.5);

		imp_enemys = new Ship::Ship(this, *this->imp_enemyImage, Coordinate(0,0));
		imp_enemys->SetStartCoordinate(Coordinate(150,-imp_enemys->GetSprite()->GetSurface()->h));
		imp_enemys->SetAngle(-10.0);
		imp_enemys->SetSpeed(-2.0);

		imp_enemys = new Ship::Ship(this, *this->imp_enemyImage, Coordinate(0,0));
		imp_enemys->SetStartCoordinate(Coordinate(250,-imp_enemys->GetSprite()->GetSurface()->h));
		imp_enemys->SetAngle(0.0);
		imp_enemys->SetSpeed(-2.0);

		imp_enemys = new Ship::Ship(this, *this->imp_enemyImage, Coordinate(0,0));
		imp_enemys->SetStartCoordinate(Coordinate(370,-imp_enemys->GetSprite()->GetSurface()->h));
		imp_enemys->SetAngle(-10.0);
		imp_enemys->SetSpeed(-3.0);
	}
}