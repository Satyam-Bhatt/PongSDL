#pragma once
#include "GameState.h"
class PlayState;

extern void setNextState(GameState* state);

class IntroState : public GameState
{
public:
	void start(SDL_Renderer* renderer);
	void update();
	void render(SDL_Renderer* renderer);
	void handleInput(SDL_Event e);
	void exit();

	//Static Accessor
	static IntroState* getIntroState();

private:
	static IntroState instance;
	Texture testTex;
};

