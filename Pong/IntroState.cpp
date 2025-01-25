#include "IntroState.h"
#include "PlayState.h"

IntroState IntroState::instance;

void IntroState::start(SDL_Renderer* renderer)
{
	if (!testTex.LoadFromFile("Images/texture.png", renderer))
	{
		printf("Failed to load texture!\n");
	}
	button = Button(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 50, 200, 100, { 255,0,0,255 }, [this]() { this->playButtonFunction(); });

	if(!buttonText.LoadText(font, "Fonts/Star Shield.ttf", "PLAY", { 0, 255, 0 }, 32, renderer))
	{
		printf("Failed to load texture!\n");
	}
}

void IntroState::update()
{
	
}

void IntroState::render(SDL_Renderer* renderer)
{
	testTex.Render(0, 0, renderer);
	button.Render(renderer);
	buttonText.Render(SCREEN_WIDTH / 2 - buttonText.GetWidth() / 2, SCREEN_HEIGHT / 2 - buttonText.GetHeight() / 2, renderer);
}

void IntroState::handleInput(SDL_Event e)
{
	button.HandleEvents(&e);
}

void IntroState::exit()
{
	testTex.Free();
	buttonText.Free();
	TTF_CloseFont(font);
	font = NULL;
}

IntroState* IntroState::getIntroState()
{
	return &instance;
}

void IntroState::playButtonFunction()
{
	setNextState(PlayState::getPlayState());
}
