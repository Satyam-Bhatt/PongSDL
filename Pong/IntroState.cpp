#include "IntroState.h"
#include "PlayState.h"

IntroState IntroState::instance;

void IntroState::start()
{
}

void IntroState::update()
{
	printf("Intro\n");
}

void IntroState::render()
{
}

void IntroState::handleInput(SDL_Event e)
{
	if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
		setNextState(PlayState::getPlayState());
}

void IntroState::exit()
{
}

IntroState* IntroState::getIntroState()
{
	return &instance;
}
