#include "PlayState.h"
#include "CollisionDetection.h"
#include <stdio.h>

PlayState PlayState::instance;

PlayState::PlayState()
{
	ball = { 0, 0 };
	font = nullptr;
	font2 = nullptr;
	music = NULL;
}

void PlayState::start(SDL_Renderer* renderer)
{
	font = TTF_OpenFont("Fonts/Star Shield.ttf", 32);
	font2 = TTF_OpenFont("Fonts/Star Shield.ttf", 100);

	if (!background.LoadFromFile("Images/bg_black.jpg", renderer))
	{
		printf("Failed to load texture!\n");
	}
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
	if (!restartInstructions.LoadText(font, "Fonts/Star Shield.ttf", "Press R to Restart", { 255, 255, 255 }, 32, renderer))
	{
		printf("Failed to load restart instructions!\n");
	}
	if(!Music::GetInstance().LoadMusic("Sounds/AIMusic.mp3", music))
	{
		printf("Failed to load music!\n");
	}

	Mix_PlayMusic(music, -1);

	//TODO: Make it scale with screen size
	paddle1 = { 10, ScreenSizeManager::getInstance().GetHeight() / 2 - 50, 50, 100 };
	ball = { ScreenSizeManager::getInstance().GetWidth()/2, ScreenSizeManager::getInstance().GetHeight() / 2 };

	aiPaddle = { ScreenSizeManager::getInstance().GetWidth() - 60, ScreenSizeManager::getInstance().GetHeight() / 2 - 50, 50, 100 };

	ball.Start();
	paddle1.Start();
	aiPaddle.Start();

	escapeOverlay.Start(renderer);
}

void PlayState::update()
{
	if (isPaused) return;

	paddle1.Update();
	aiPaddle.Update();

	aiPaddle.GetBallDirection(&ball);
	ball.Update(paddle1.GetRect(), aiPaddle.GetRect());
}

void PlayState::render(SDL_Renderer* renderer)
{
	background.RenderFullScreen(renderer);
	paddle1.Render(renderer);
	aiPaddle.Render(renderer);

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
	restartInstructions.Render(ScreenSizeManager::getInstance().GetWidth() / 2 - restartInstructions.GetWidth() / 2, ScreenSizeManager::getInstance().GetHeight() / 2 + 100, renderer);

	ball.Render(renderer);

	if (isPaused)escapeOverlay.Render(renderer);
}

void PlayState::handleInput(SDL_Event e)
{
	if (isPaused)escapeOverlay.HandleEvents(e);

	else
	{
		paddle1.HandleEvents(e);
		ball.HandleEvents(e);
	}

	if (e.type == SDL_WINDOWEVENT)
	{
		switch (e.window.event)
		{
		case SDL_WINDOWEVENT_RESIZED:
			aiPaddle = { e.window.data1 - 60, 50, 50, 100 };
		}
	}

	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_r:
			setNextState(PlayState::getPlayState());
			break;

		case SDLK_ESCAPE:
			isPaused = !isPaused;
			break;
		}
	}
}

void PlayState::exit()
{
	isPaused = false;
	paddle1.Close();
	aiPaddle.Close();
	playInstructions.Free();
	restartInstructions.Free();
	background.Free();
	rightNumber.Free();
	leftNumber.Free();
	escapeOverlay.Exit();
	TTF_CloseFont(font);
	TTF_CloseFont(font2);
	font = nullptr;
	font2 = nullptr;
	Mix_HaltMusic();
	Mix_FreeMusic(music);
	music = NULL;
}

PlayState* PlayState::getPlayState()
{
	return &instance;
}

bool PlayState::Approximate(float a, float b, float epsilon)
{
	return abs(a - b) < epsilon;
}
