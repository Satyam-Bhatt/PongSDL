#pragma once
#include <SDL.h>

class Button
{
public:
	Button(int x, int y, int w, int h);

	void Render(SDL_Renderer* renderer);
	void HandleEvents(SDL_Event* e);

private:
	SDL_Rect button_Rect;
	SDL_Color color;
};

