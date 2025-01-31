#include "Ball.h"
#include "CollisionDetection.h"
#include <stdio.h>

Ball::Ball(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
	ballRect = { posX, posY, BALL_RADIUS, BALL_RADIUS };
	velocityX = 0;
	velocityY = 0;
}

void Ball::Start()
{
	velocityX = BALL_SPEED;
	velocityY = 0;
}

void Ball::Update()
{
	float dt = Timer::getInstance().GetDeltaTime();
	posX += velocityX * dt;
	posY += velocityY * dt;

	ballRect = { (int)posX, (int)posY, BALL_RADIUS, BALL_RADIUS };
}

void Ball::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer , &ballRect);
}

void Ball::HandleEvents(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_p:
			printf("Paused\n");
			velocityX = - velocityX;
			break;
		}
	}
}

void Ball::Close()
{
	posX = 0;
	posY = 0;
	ballRect = { 0, 0, 0, 0 };
}

void Ball::CollidedWithPaddle(SDL_Rect paddle1, SDL_Rect paddle2)
{
	if (CollisionDetection::GetInstance().CheckCollision(ballRect, paddle1) || CollisionDetection::GetInstance().CheckCollision(ballRect, paddle2))
	{
		velocityX = -velocityX;
	}
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
