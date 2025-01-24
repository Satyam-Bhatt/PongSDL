#include "Button.h"
#include <stdio.h>

Button::Button(int x, int y, int w, int h, SDL_Color _color, void(*actionToPerform)())
{
	button_Rect = { x, y, w, h };
	colorStored = _color;
	color = _color;
	buttonFunction = actionToPerform;
}

void Button::HandleEvents(SDL_Event* e)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		int mouse_x, mouse_y;
		SDL_GetMouseState(&mouse_x, &mouse_y);

		bool inside = true;

		if(mouse_x < button_Rect.x)
			inside = false;
		else if(mouse_x > button_Rect.x + button_Rect.w)
			inside = false;
		else if(mouse_y < button_Rect.y)
			inside = false;
		else if(mouse_y > button_Rect.y + button_Rect.h)
			inside = false;

		if (!inside)
		{
			color = colorStored;
		}
		else
		{
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				color = { Uint8(colorStored.r * 0.9), Uint8(colorStored.g * 0.9), Uint8(colorStored.b * 0.9), 255};
				break;
			case SDL_MOUSEBUTTONDOWN:
				color = { Uint8(colorStored.r * 0.7), Uint8(colorStored.g * 0.7), Uint8(colorStored.b * 0.7), 255 };
				break;
			case SDL_MOUSEBUTTONUP:
				color = { Uint8(colorStored.r * 0.9), Uint8(colorStored.g * 0.9), Uint8(colorStored.b * 0.9), 255 };
				buttonFunction();
				break;
			}
		}
	}
}

void Button::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &button_Rect);
}