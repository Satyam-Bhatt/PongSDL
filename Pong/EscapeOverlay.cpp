#include "EscapeOverlay.h"
#include "IntroState.h"

void EscapeOverlay::Start()
{
	mainMenu_Button = Button({ 255,255,0,255 }, [this]() { this->MainMenuButton(); });
	quit_Button = Button({ 255,0,0,255 }, [this]() { this->QuitButton(); });
}

void EscapeOverlay::Update()
{
}

void EscapeOverlay::Render(SDL_Renderer* renderer)
{
	SDL_Rect fullScreenOverlay = {0,0,ScreenSizeManager::getInstance().GetWidth(),ScreenSizeManager::getInstance().GetHeight()};
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128);
	SDL_RenderFillRect(renderer, &fullScreenOverlay);

	SDL_Rect button_Rect = {ScreenSizeManager::getInstance().GetWidth() / 2 - 200 / 2, ScreenSizeManager::getInstance().GetHeight() / 2 - 100 / 2, 200, 100};
	mainMenu_Button.Render(button_Rect ,renderer);

	SDL_Rect button_Rect2 = { ScreenSizeManager::getInstance().GetWidth() / 2 - 200 / 2, ScreenSizeManager::getInstance().GetHeight() / 2 + 200 / 2, 200, 100 };
	quit_Button.Render(button_Rect2, renderer);
}

void EscapeOverlay::HandleEvents(SDL_Event& e)
{
	mainMenu_Button.HandleEvents(&e);
	quit_Button.HandleEvents(&e);
}

void EscapeOverlay::MainMenuButton()
{
	setNextState(IntroState::getIntroState());
}

void EscapeOverlay::QuitButton()
{
	exit(0);
}
