#ifndef GAME_H
#define GAME_H

#include "GameEngine.h"
#include "Weapon.h"
#include "Ship.h"
/*
	Inherits gameengine, 
	the only thing that has to be done is to define
	what objects that is suposed to be loaded
	and what to do with them.

	Author: Mikael Hallgren 2013
*/
#include "ShipPlayer.h"

using namespace Engine;
using namespace Graphics;

class Game : public GameEngine
{
private:

	TTF_Font * fontBig;		// pointer to loaded font
	TTF_Font * fontSmal;	// pointer to loaded font

	Graphics::Backdrop * backdrop;		// backdrop with, slowmoving
	Graphics::Backdrop * secondBack;	// backdrop that gives the perception of depth

	Graphics::Image * imp_enemyImage;	// enemyships image

	Ship::ShipPlayer * imp_player;		// Playership pointer
	Ship::Ship *			 imp_enemys;		// enemy ship pointer

	Sprite::FontSprite * bigCenterText;		// Fontsprite 1
	Sprite::FontSprite * smallCenterText;	// Font sprite 2

	int	 imp_bufferTimer;				// is used to handle countdown
	bool imp_waitingForPlayer;	// case when user must press space to begin, startstate
	bool imp_gameRunning;				// game is running after countdown
	bool imp_playerDead;				// player life ended, game over.
	bool imp_countDown;					// countdown flag

	void generateBadGuys();

public:
	Game();
	~Game();
	void BackdropDraw();
	void Update();
	void Load();
};

#endif
