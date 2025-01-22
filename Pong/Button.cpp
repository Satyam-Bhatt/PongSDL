#include "Button.h"
#include <stdio.h>

Button::Button(int x, int y, int w, int h)
{
	button_Rect = { x, y, w, h };
	color = { 255, 255, 255, 255 };
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
			color = { 255, 255, 255, 255 };
		}
		else
		{
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				color = { 200, 200, 200, 255 };
				break;
			case SDL_MOUSEBUTTONDOWN:
				color = { 150, 150, 150, 255 };
				break;
			case SDL_MOUSEBUTTONUP:
				color = { 200, 200, 200, 255 };
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