#pragma once
#include <SDL.h>
#include <stdio.h>

class GameState
{
public: 
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleInput(SDL_Event e) = 0;
	virtual void exit() = 0;

};

