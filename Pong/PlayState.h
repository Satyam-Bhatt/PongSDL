#pragma once
#include "GameState.h"
class PlayState :
	public GameState
{
public:
	void start();
	void update();
	void render();
	void handleInput();
	void exit();
};

