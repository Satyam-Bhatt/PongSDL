#include "IntroState.h"
#include "PlayState.h"
#include "PlayState_Player.h"

IntroState IntroState::instance;

void IntroState::start(SDL_Renderer* renderer)
{
	if (!testTex.LoadFromFile("Images/bg_main.jpg", renderer))
	{
		printf("Failed to load texture!\n");
	}
	ai_Button = Button({ 255,0,0,255 }, [this]() { this->playButtonFunction(); });

	if(!buttonText.LoadText(font, "Fonts/Star Shield.ttf", "PLAY AI", { 0, 255, 0 }, 32, renderer))
	{
		printf("Failed to load texture!\n");
	}

	playerButton = Button({ 255,255,0,255 }, [this]() { this->playPlayerButtonFunction(); });

	if(!playerButtonText.LoadText(font, "Fonts/Star Shield.ttf", "PLAY PLAYER", { 0, 255, 0 }, 32, renderer))
	{
		printf("Failed to load texture!\n");
	}

	if(!Music::GetInstance().LoadMusic("Sounds/beat.mp3", music))
	{
		printf("Failed to load music!\n");
	}

	Mix_PlayMusic(music, -1);
}

void IntroState::update()
{
	
}

void IntroState::render(SDL_Renderer* renderer)
{
	testTex.RenderFullScreen(renderer);

	SDL_Rect button_Rect = {ScreenSizeManager::getInstance().GetWidth() / 2 - 200 / 2, ScreenSizeManager::getInstance().GetHeight() / 2 - 100 / 2, 200, 100};
	ai_Button.Render(button_Rect ,renderer);
	buttonText.Render(button_Rect.x + button_Rect.w / 2 - buttonText.GetWidth() / 2, button_Rect.y + button_Rect.h / 2 - buttonText.GetHeight() / 2, renderer);

	SDL_Rect button_Rect2 = { ScreenSizeManager::getInstance().GetWidth() / 2 - 200 / 2, ScreenSizeManager::getInstance().GetHeight() / 2 + 200 / 2, 200, 100 };
	playerButton.Render(button_Rect2, renderer);
	playerButtonText.Render(button_Rect2.x + button_Rect2.w / 2 - playerButtonText.GetWidth() / 2, button_Rect2.y + button_Rect2.h / 2 - playerButtonText.GetHeight() / 2, renderer);
}

void IntroState::handleInput(SDL_Event e)
{
	ai_Button.HandleEvents(&e);
	playerButton.HandleEvents(&e);
}

void IntroState::exit()
{
	testTex.Free();
	buttonText.Free();
	TTF_CloseFont(font);
	font = NULL;

	Mix_HaltMusic();
	Mix_FreeMusic(music);
	music = NULL;
}

IntroState* IntroState::getIntroState()
{
	return &instance;
}

void IntroState::playButtonFunction()
{
	setNextState(PlayState::getPlayState());
}

void IntroState::playPlayerButtonFunction()
{
	setNextState(PlayState_Player::getPlayState_Player());
}


