#include "EscapeOverlay.h"
#include "IntroState.h"

EscapeOverlay::EscapeOverlay()
{
	fontNew = nullptr;
}

void EscapeOverlay::Start(SDL_Renderer* renderer)
{
	fontNew = TTF_OpenFont("Fonts/Star Shield.ttf", 32);
	mainMenu_Button = Button({ 255,255,0,255 }, [this]() { this->MainMenuButton(); });
	quit_Button = Button({ 255,0,0,255 }, [this]() { this->QuitButton(); });

	if (!mainMenu_Text.LoadText(fontNew, "Fonts/Star Shield.ttf", "Main Menu", { 0, 0, 0 }, 32, renderer))
	{
		printf("Failed to load play instructions!\n");
	}

	if (!quitButton_Text.LoadText(fontNew, "Fonts/Star Shield.ttf", "Quit", { 0, 0, 0 }, 32, renderer))
	{
		printf("Failed to load play instructions!\n");
	}
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

	mainMenu_Text.Render(button_Rect.x + button_Rect.w / 2 - mainMenu_Text.GetWidth() / 2, button_Rect.y + button_Rect.h / 2 - mainMenu_Text.GetHeight() / 2, renderer);
	quitButton_Text.Render(button_Rect2.x + button_Rect2.w / 2 - quitButton_Text.GetWidth() / 2, button_Rect2.y + button_Rect2.h / 2 - quitButton_Text.GetHeight() / 2, renderer);
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

void EscapeOverlay::Exit()
{
	TTF_CloseFont(fontNew);
	fontNew = nullptr;
	mainMenu_Text.Free();
	quitButton_Text.Free();
}
