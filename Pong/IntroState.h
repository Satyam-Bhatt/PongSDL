#pragma once
#include "GameState.h"
#include "Button.h"

class PlayState;
class PlayState_Player;

extern void setNextState(GameState* state);

class IntroState : public GameState
{
public:
	void start(SDL_Renderer* renderer) override;
	void update() override;
	void render(SDL_Renderer* renderer) override;
	void handleInput(SDL_Event e) override;
	void exit() override;
	void playButtonFunction();
	void playPlayerButtonFunction();
	//Static Accessor
	static IntroState* getIntroState();

private:
	static IntroState instance;
	Texture testTex;
	Button ai_Button;
	Texture buttonText;

	Button playerButton;
	Texture playerButtonText;

	TTF_Font* font = NULL;

	Mix_Music* music = NULL;
	Mix_Chunk* sfx = NULL;
};

