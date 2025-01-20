#pragma once
#include "GameState.h"

class IntroState;

class PlayState :
	public GameState
{
public:
	void start();
	void update();
	void render();
	void handleInput(SDL_Event e);
	void exit();

	//Static accessor
	static PlayState* getPlayState();

private:
	static PlayState instance;
};

