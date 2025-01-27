#pragma once
#include "GameState.h"
#include "Button.h"

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
	void playButtonFunction();

	//Static Accessor
	static IntroState* getIntroState();

private:
	static IntroState instance;
	Texture testTex;
	Button button = Button({0,0,0,0}, []() { printf("Button Pressed\n"); });
	Texture buttonText;
	TTF_Font* font = NULL;
};

