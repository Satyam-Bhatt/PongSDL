#include "PlayState.h"
#include "IntroState.h"

PlayState PlayState::instance;

void PlayState::start(SDL_Renderer* renderer)
{
}

void PlayState::update()
{
	printf("Play\n");
}

void PlayState::render(SDL_Renderer* renderer)
{
}

void PlayState::handleInput(SDL_Event e)
{
}

void PlayState::exit()
{
}

PlayState* PlayState::getPlayState()
{
	return &instance;
}
