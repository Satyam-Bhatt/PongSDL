#pragma once
#include "GameState.h"
#include "Paddle.h"

class IntroState;

class PlayState :
	public GameState
{
public:
	PlayState();
	void start(SDL_Renderer* renderer);
	void update();
	void render(SDL_Renderer* renderer);
	void handleInput(SDL_Event e);
	void exit();

	//Static accessor
	static PlayState* getPlayState();

private:
	static PlayState instance;
	Paddle paddle1;
};

