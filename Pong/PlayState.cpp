#include "PlayState.h"
#include "IntroState.h"
#include "CollisionDetection.h"
#include <stdio.h>

PlayState PlayState::instance;

PlayState::PlayState() : ball(0, 0)
{

}

void PlayState::start(SDL_Renderer* renderer)
{
	if (!playInstructions.LoadText(font, "Fonts/Star Shield.ttf", "Press Space to Start", { 255, 255, 255 }, 32, renderer))
	{
		printf("Failed to load play instructions!\n");
	}

	//TODO: Make it scale with screen size
	paddle1 = { 10, 50, 50, 100 };
	paddle2 = { ScreenSizeManager::getInstance().GetWidth() - 60, 250, 50, 100 };
	ball = { ScreenSizeManager::getInstance().GetWidth() / 2, ScreenSizeManager::getInstance().GetHeight() / 2};

	ball.Start();
}

void PlayState::update()
{
	paddle1.Update();
	paddle2.Update();

	ball.Update(paddle1.GetRect(), paddle2.GetRect());
}

void PlayState::render(SDL_Renderer* renderer)
{
	paddle1.Render(renderer);
	paddle2.Render(renderer);
	ball.Render(renderer);

	if(ball.GetReset()) playInstructions.Render(ScreenSizeManager::getInstance().GetWidth() / 2 - playInstructions.GetWidth() / 2, ScreenSizeManager::getInstance().GetHeight() / 2 + 50, renderer);
}

void PlayState::handleInput(SDL_Event e)
{
	paddle1.HandleEvents(e);
	paddle2.HandleEvents(e);
	ball.HandleEvents(e);

	if (e.type == SDL_WINDOWEVENT)
	{
		switch (e.window.event)
		{
		case SDL_WINDOWEVENT_RESIZED:
			paddle2 = { e.window.data1 - 60, 50, 50, 100 };
		}
	}

	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_r:
			setNextState(PlayState::getPlayState());
			break;
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
