#include "PlayState_Player.h"

PlayState_Player PlayState_Player::instance;

PlayState_Player::PlayState_Player()
{
    ball = { 0, 0 };
    font = nullptr;
    font2 = nullptr;
}

void PlayState_Player::start(SDL_Renderer* renderer)
{
	font = TTF_OpenFont("Fonts/Star Shield.ttf", 32);
	font2 = TTF_OpenFont("Fonts/Star Shield.ttf", 100);

	if (!playInstructions.LoadText(font, "Fonts/Star Shield.ttf", "Press Space to Start", { 255, 255, 255 }, 32, renderer))
	{
		printf("Failed to load play instructions!\n");
	}
	if (!rightNumber.LoadText(font, "Fonts/Star Shield.ttf", "0", { 170, 170, 170 }, 100, renderer))
	{
		printf("Failed to load rightNumber\n");
	}
	if (!leftNumber.LoadText(font, "Fonts/Star Shield.ttf", "0", { 170, 170, 170 }, 100, renderer))
	{
		printf("Failed to load leftNumber\n");
	}

	//TODO: Make it scale with screen size
	paddle1 = { 10, ScreenSizeManager::getInstance().GetHeight() / 2 - 50, 50, 100 };
	otherPaddle = { ScreenSizeManager::getInstance().GetWidth() - 60, ScreenSizeManager::getInstance().GetHeight() / 2 - 50, 50, 100 };
	ball = { ScreenSizeManager::getInstance().GetWidth() / 2, ScreenSizeManager::getInstance().GetHeight() / 2 };

	ball.Start();
	escapeOverlay.Start(renderer);
}

void PlayState_Player::update()
{
	paddle1.Update();
	otherPaddle.Update();

	ball.Update(paddle1.GetRect(), otherPaddle.GetRect());
}

void PlayState_Player::render(SDL_Renderer* renderer)
{
	paddle1.Render(renderer);
	otherPaddle.Render(renderer);
	ball.Render(renderer);


	if (ball.GetReset())
	{
		playInstructions.Render(ScreenSizeManager::getInstance().GetWidth() / 2 - playInstructions.GetWidth() / 2, ScreenSizeManager::getInstance().GetHeight() / 2 + 50, renderer);

		if (!rightNumber.LoadTextWithoutOpeningFont(font2, std::to_string(ball.GetRightScore()).c_str(), { 170, 170, 170 }, renderer))
		{
			printf("Failed to load rightNumber\n");
		}

		if (!leftNumber.LoadTextWithoutOpeningFont(font2, std::to_string(ball.GetLeftScore()).c_str(), { 170, 170, 170 }, renderer))
		{
			printf("Failed to load rightNumber\n");
		}
	}

	rightNumber.Render(ScreenSizeManager::getInstance().GetWidth() / 2 + rightNumber.GetWidth() + 50, ScreenSizeManager::getInstance().GetHeight() / 2 - rightNumber.GetHeight() / 2, renderer);
	leftNumber.Render(ScreenSizeManager::getInstance().GetWidth() / 2 - leftNumber.GetWidth() - 50, ScreenSizeManager::getInstance().GetHeight() / 2 - leftNumber.GetHeight() / 2, renderer);
	if(isPaused) escapeOverlay.Render(renderer);
}

void PlayState_Player::handleInput(SDL_Event e)
{
	paddle1.HandleEvents(e);
	otherPaddle.HandleEvents(e);
	ball.HandleEvents(e);
	if(isPaused)escapeOverlay.HandleEvents(e);

	if (e.type == SDL_WINDOWEVENT)
	{
		switch (e.window.event)
		{
		case SDL_WINDOWEVENT_RESIZED:
			otherPaddle = { e.window.data1 - 60, 50, 50, 100 };
		}
	}

	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_r:
			setNextState(PlayState_Player::getPlayState_Player());
			break;
		case SDLK_ESCAPE:
			isPaused = !isPaused;
		}
	}
}

void PlayState_Player::exit()
{
	paddle1.Close();
	otherPaddle.Close();
	playInstructions.Free();
	rightNumber.Free();
	leftNumber.Free();
	TTF_CloseFont(font);
	TTF_CloseFont(font2);
	font = NULL;
	font2 = NULL;
}

PlayState_Player* PlayState_Player::getPlayState_Player()
{
    return &instance;
}