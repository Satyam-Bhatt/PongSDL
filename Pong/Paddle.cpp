#include "Paddle.h"
#include <stdio.h>

Paddle::Paddle(int _posX, int _posY, int _width, int _height)
{
	posX = _posX;
	posY = _posY;
	paddleRect = {_posX, _posY, _width, _height};
	velocity = 0;
}

Paddle::~Paddle()
{
	Close();
}

void Paddle::Close()
{
	posX = 0;
	posY = 0;
	paddleRect = { 0, 0, 0, 0 };
}

void Paddle::Update()
{
	posY += velocity;

	paddleRect = { posX, posY, paddleRect.w, paddleRect.h };
}

SDL_Rect Paddle::GetRect()
{
	return paddleRect;
}

int Paddle::GetX()
{
	return posX;
}

int Paddle::GetY()
{
	return posY;
}

void Paddle::HandleEvents(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.sym)
		{
		case SDLK_UP:
			velocity = -PADDLE_VELOCITY;
			break;
		case SDLK_DOWN:
			velocity = PADDLE_VELOCITY;
			break;
		}
	}
	else if (e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			velocity = 0;
			break;
		case SDLK_DOWN:
			velocity = 0;
			break;
		}
	}
}

void Paddle::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &paddleRect);
}