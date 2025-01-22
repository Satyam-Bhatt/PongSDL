#include "IntroState.h"
#include "PlayState.h"

IntroState IntroState::instance;

void IntroState::start(SDL_Renderer* renderer)
{
	if (!testTex.LoadFromFile("Images/texture.png", renderer))
	{
		printf("Failed to load texture!\n");
	}
	button = Button(0, 0, 100, 100);
}

void IntroState::update()
{
	
}

void IntroState::render(SDL_Renderer* renderer)
{
	//testTex.Render(0, 0, renderer);
	button.Render(renderer);
}

void IntroState::handleInput(SDL_Event e)
{
	if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
		setNextState(PlayState::getPlayState());

	button.HandleEvents(&e);
}

void IntroState::exit()
{
	testTex.Free();
}

IntroState* IntroState::getIntroState()
{
	return &instance;
}
