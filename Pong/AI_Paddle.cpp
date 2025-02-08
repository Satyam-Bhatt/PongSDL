#include "AI_Paddle.h"
#include <cmath>

AI_Paddle::AI_Paddle(int _posX, int _posY, int _width, int _height)
{
	posX = _posX;
	posY = _posY;
	paddleRect = { _posX, _posY, _width, _height };
	velocity = PADDLE_VELOCITY;
}

void AI_Paddle::Update()
{
	posY += velocity * Timer::getInstance().GetDeltaTime();

	if (posY > ScreenSizeManager::getInstance().GetHeight() - paddleRect.h)
	{
		posY = ScreenSizeManager::getInstance().GetHeight() - paddleRect.h;
	}
	else if (posY < 0)
	{
		posY = 0;
	}

	paddleRect = { posX, posY, paddleRect.w, paddleRect.h };
}

void AI_Paddle::GetBallDirection(Ball* ball)
{
	//printf("Ball dir y: %f\n", ball->GetDirY());
    int ballDirY = std::abs(ball->GetDirY())/ball->GetDirY();
	printf("Ball dir y: %d\n", ballDirY);
	velocity *= ballDirY;
}

