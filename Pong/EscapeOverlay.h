#pragma once
#include "Button.h"
#include <SDL.h>
#include "GameState.h"

extern void setNextState(GameState* state);

class EscapeOverlay
{
public: 
	EscapeOverlay() = default;
	void Start();
	void Update();
	void Render(SDL_Renderer* renderer);
	void HandleEvents(SDL_Event& e);
	void MainMenuButton();
	void QuitButton();

private:
	Button mainMenu_Button, quit_Button;

};

