#pragma once
#include "GameState.h"
#include "Paddle.h"
#include "Ball.h"

extern void setNextState(GameState* state);

class PlayState_Player :
    public GameState
{
public: 
	PlayState_Player();
	void start(SDL_Renderer* renderer) override;
	void update() override;
	void render(SDL_Renderer * renderer) override;
	void handleInput(SDL_Event e) override;
	void exit() override;

	//Static accessor
	static PlayState_Player* getPlayState_Player();

private:
	static PlayState_Player instance;
	Paddle paddle1;
	Paddle paddle2;
	Ball ball;
	Texture playInstructions;
	Texture rightNumber, leftNumber;
	TTF_Font* font;
	TTF_Font* font2;
};

