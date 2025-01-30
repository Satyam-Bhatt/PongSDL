#include "Ball.h"

Ball::Ball(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
	ballRect = { posX, posY, BALL_RADIUS, BALL_RADIUS };
}

void Ball::Start()
{
	velocityX = BALL_SPEED;
	velocityY = 0;
}

void Ball::Update()
{
	posX += velocityX * Timer::getInstance().GetDeltaTime();
	posY += velocityY * Timer::getInstance().GetDeltaTime();

	ballRect = {posX, posY, BALL_RADIUS, BALL_RADIUS};
}

void Ball::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer , &ballRect);
}

void Ball::HandleEvents(SDL_Event e)
{

}

void Ball::Close()
{
	posX = 0;
	posY = 0;
	ballRect = { 0, 0, 0, 0 };
}

SDL_Rect Ball::GetBallRect()
{
	return ballRect;
}

int Ball::GetX()
{
	return posX;
}

int Ball::GetY()
{
	return posY;
}
