#include "PlayState.h"
#include "IntroState.h"
#include <iostream>

PlayState PlayState::instance;

PlayState::PlayState()
{
	paddle1 = { 10, 50, 50, 100 };
}

void PlayState::start(SDL_Renderer* renderer)
{
}

void PlayState::update()
{
	paddle1.Update();
}

void PlayState::render(SDL_Renderer* renderer)
{
	paddle1.Render(renderer);
}

void PlayState::handleInput(SDL_Event e)
{
	paddle1.HandleEvents(e);
}

void PlayState::exit()
{
}

PlayState* PlayState::getPlayState()
{
	return &instance;
}
