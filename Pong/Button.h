#pragma once
#include <SDL.h>
#include <functional>

class Button
{
	typedef std::function<void()> ButtonFunction;

public:
	Button(int x, int y, int w, int h, SDL_Color _color, std::function<void()> OnClickFunction);

	void Render(SDL_Renderer* renderer);
	void HandleEvents(SDL_Event* e);

private:
	SDL_Rect button_Rect;
	SDL_Color color;
	SDL_Color colorStored;

	ButtonFunction buttonFunction;
};

