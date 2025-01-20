#include "PlayState.h"
#include "IntroState.h"

PlayState PlayState::instance;

void PlayState::start()
{
}

void PlayState::update()
{
	printf("Play\n");
}

void PlayState::render()
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
