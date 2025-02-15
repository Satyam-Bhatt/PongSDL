#include "AI_Paddle.h"
#include <cmath>

AI_Paddle::AI_Paddle(int _posX, int _posY, int _width, int _height)
{
	posX = _posX;
	posY = _posY;
	paddleRect = { _posX, _posY, _width, _height };
	velocity = PADDLE_VELOCITY;
	direction = 0;
}

void AI_Paddle::Update()
{
	posY += direction * (velocity + aiSpeedIncrease) * Timer::getInstance().GetDeltaTime();

	if (posY > ScreenSizeManager::getInstance().GetHeight() - paddleRect.h)
	{
		posY = ScreenSizeManager::getInstance().GetHeight() - paddleRect.h;
	}
	else if (posY < 0)
	{
		posY = 0;
	}

	paddleRect = { (int)posX, (int)posY, paddleRect.w, paddleRect.h };
}

void AI_Paddle::GetBallDirection(Ball* ball)
{
	SDL_Rect ballRect = ball->GetBallRect();
	int ballPosY = ballRect.y + ballRect.h / 2;
	int paddlePosY = paddleRect.y + paddleRect.h / 2;

	if (paddlePosY > ballPosY)
	{
		direction = -1;
	}
	else if (paddlePosY < ballPosY)
	{
		direction = 1;
	}
	else
	{
		direction = 0;
	}

	if (ball->GetReset())
	{
		direction = 0;
	}
}

