#pragma once
#include "GameState.h"
#include "Paddle.h"
#include "Ball.h"
#include "AI_Paddle.h"

class IntroState;
extern void setNextState(GameState* state);

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
	Paddle paddle2;
	AI_Paddle aiPaddle;
	Ball ball;
	Texture playInstructions;
	Texture rightNumber, leftNumber;
	TTF_Font* font;
	TTF_Font* font2;
};

