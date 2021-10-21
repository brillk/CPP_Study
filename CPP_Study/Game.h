#pragma once
#include "Player.h"


//is - a / has - a 

//전방선언
class Player;
class Field;

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();
private:
	Player* _player;
	Field* _field;
};

