#pragma once
#include "GameState.h"
class PlayState;

extern void setNextState(GameState* state);

class IntroState : public GameState
{
public:
	void start();
	void update();
	void render();
	void handleInput(SDL_Event e);
	void exit();

	//Static Accessor
	static IntroState* getIntroState();

private:
	static IntroState instance;
};

