#include "Ball.h"
#include "CollisionDetection.h"
#include <stdio.h>
#include <cmath>
#include "ScreenSizeManager.h"

Ball::Ball(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
	ballRect = { posX, posY, BALL_RADIUS, BALL_RADIUS };
	velocity = 0;
	dirX = 0;
	dirY = 0;
}

void Ball::Start()
{
	velocity = BALL_SPEED;
	dirX = 1;
	dirY = 1;
}

void Ball::Update(SDL_Rect paddle1, SDL_Rect paddle2)
{
	float dt = Timer::getInstance().GetDeltaTime();
	float normalizedDirection = NormalizeDirection(dirX, dirY);
	posX += dirX/normalizedDirection * velocity * dt;
	posY += dirY/normalizedDirection * velocity * dt;

	if (CollisionDetection::GetInstance().CheckCollision(ballRect, paddle1) || CollisionDetection::GetInstance().CheckCollision(ballRect, paddle2))
	{
		printf("Collision\n");
		posX -= dirX / normalizedDirection * velocity * dt;
		posY -= dirY / normalizedDirection * velocity * dt;

		if (ballRect.x + BALL_RADIUS - 1 > paddle2.x || ballRect.x  + 1 < paddle1.x + paddle1.w)
		{
			float reflectedAngele = ReflectedAngle(dirX / normalizedDirection, dirY / normalizedDirection);
			dirX = -cos(reflectedAngele);
			dirY = -sin(reflectedAngele);
			posX += dirX * velocity * dt;
			posY += dirY * velocity * dt;
		}
		else
		{
			float reflectedAngele = ReflectedAngle(dirX / normalizedDirection, dirY / normalizedDirection);
			dirX = - cos(reflectedAngele);
			dirY = sin(reflectedAngele);
			posX += dirX  * velocity * dt;
			posY += dirY  * velocity * dt;
		}

	}

	if(posY < 0)
	{
		posY = 0;

		float reflectedAngele = ReflectedAngle(dirX / normalizedDirection, dirY / normalizedDirection);
		dirX = cos(reflectedAngele);
		dirY = -sin(reflectedAngele);
		posX += dirX * velocity * dt;
		posY += dirY * velocity * dt;
	}
	else if(posY > ScreenSizeManager::getInstance().GetHeight() - BALL_RADIUS)
	{
		posY = ScreenSizeManager::getInstance().GetHeight() - BALL_RADIUS;

		float reflectedAngele = ReflectedAngle(dirX / normalizedDirection, dirY / normalizedDirection);
		dirX = cos(reflectedAngele);
		dirY = -sin(reflectedAngele);
		posX += dirX * velocity * dt;
		posY += dirY * velocity * dt;
	}

	ballRect = { (int)posX, (int)posY, BALL_RADIUS, BALL_RADIUS };
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

float Ball::NormalizeDirection(float directionX, float directionY)
{
	return sqrt(pow(directionX,2) + pow(directionY,2));
}

float Ball::ReflectedAngle(float directionX, float directionY)
{
    const float rad2deg = 180.0f / M_PI;
	float angle = atan2(directionY, directionX);
	return atan2(directionY, directionX);
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
