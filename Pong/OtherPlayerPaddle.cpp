#include "OtherPlayerPaddle.h"

OtherPlayerPaddle::OtherPlayerPaddle(int _posX, int _posY, int _width, int _height)
{
	posX = _posX;
	posY = _posY;
	paddleRect = { _posX, _posY, _width, _height };
	velocity = 0;
}

void OtherPlayerPaddle::HandleEvents(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			velocity = -PADDLE_VELOCITY;
			break;
		case SDLK_s:
			velocity = PADDLE_VELOCITY;
			break;
		}
	}
	else if (e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			velocity = 0;
			break;
		case SDLK_s:
			velocity = 0;
			break;
		}
	}
}
