#pragma once
#include <SDL.h>

class Button
{
	typedef void(*ButtonFunction)();

public:
	Button(int x, int y, int w, int h, SDL_Color _color, void(*actionToPerform)());

	void Render(SDL_Renderer* renderer);
	void HandleEvents(SDL_Event* e);

private:
	SDL_Rect button_Rect;
	SDL_Color color;
	SDL_Color colorStored;

	ButtonFunction buttonFunction;
};

