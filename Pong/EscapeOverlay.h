#pragma once
#include "Button.h"
#include <SDL.h>
#include "GameState.h"
#include "Texture.h"

extern void setNextState(GameState* state);

class EscapeOverlay
{
public: 
	EscapeOverlay();
	void Start(SDL_Renderer* renderer);
	void Update();
	void Render(SDL_Renderer* renderer);
	void HandleEvents(SDL_Event& e);
	void MainMenuButton();
	void QuitButton();
	void Exit();

private:
	Button mainMenu_Button, quit_Button;
	Texture mainMenu_Text, quitButton_Text;
	TTF_Font* fontNew = NULL;
};

