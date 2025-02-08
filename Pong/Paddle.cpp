#include "Paddle.h"
#include <stdio.h>
#include "Timer.h"

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
	posY += velocity * Timer::getInstance().GetDeltaTime();

	if (posY > ScreenSizeManager::getInstance().GetHeight() - paddleRect.h)
	{
		posY = ScreenSizeManager::getInstance().GetHeight() - paddleRect.h;
	}
	else if(posY < 0)
	{
		posY = 0;
	}

	paddleRect = { (int)posX, (int)posY, paddleRect.w, paddleRect.h };
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

SDL_Rect Paddle::GetRect()
{
	return paddleRect;
}

float Paddle::GetX()
{
	return posX;
}

float Paddle::GetY()
{
	return posY;
}