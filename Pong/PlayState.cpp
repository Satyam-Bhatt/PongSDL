#include "PlayState.h"
#include "IntroState.h"
#include <iostream>

PlayState PlayState::instance;

PlayState::PlayState()
{

}

void PlayState::start(SDL_Renderer* renderer)
{
	//TODO: Make it scale with screen size
	paddle1 = { 10, 50, 50, 100 };
	paddle2 = { ScreenSizeManager::getInstance().GetWidth() - 60, 50, 50, 100 };
	ball = { ScreenSizeManager::getInstance().GetWidth() / 2, ScreenSizeManager::getInstance().GetHeight() / 2 };

	ball.Start();
}

void PlayState::update()
{
	paddle1.Update();
	paddle2.Update();
	ball.Update();
}

void PlayState::render(SDL_Renderer* renderer)
{
	paddle1.Render(renderer);
	paddle2.Render(renderer);
	ball.Render(renderer);
}

void PlayState::handleInput(SDL_Event e)
{
	paddle1.HandleEvents(e);
	paddle2.HandleEvents(e);

	if (e.type == SDL_WINDOWEVENT)
	{
		switch (e.window.event)
		{
		case SDL_WINDOWEVENT_RESIZED:
			paddle2 = { e.window.data1 - 60, 50, 50, 100 };
		}
	}
}

void PlayState::exit()
{
	paddle1.Close();
	paddle2.Close();
}

PlayState* PlayState::getPlayState()
{
	return &instance;
}
