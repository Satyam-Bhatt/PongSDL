#pragma once
#include <SDL.h>
#include <stdio.h>
#include "Texture.h"

class GameState
{
public: 
	virtual void start(SDL_Renderer* renderer) = 0;
	virtual void update() = 0;
	virtual void render(SDL_Renderer* renderer) = 0;
	virtual void handleInput(SDL_Event e) = 0;
	virtual void exit() = 0;

};

