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
	reset = true;
}

void Ball::Start()
{
	srand(SDL_GetTicks());

	velocity = BALL_SPEED;
	dirX = 0;
	dirY = 0;

	printf("posX: %f || posY: %f", posX, posY);
}

void Ball::Update(SDL_Rect paddle1, SDL_Rect paddle2)
{
	if (dirX == 0 && dirY == 0) return;

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

	if(posX < -1)
	{
		Reset();
	}
	else if(posX > ScreenSizeManager::getInstance().GetWidth() + 1)
	{
		Reset();
	}
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
		case SDLK_SPACE:
			if (reset == true)
			{
				float angle = static_cast<float>((rand() % 360) * M_PI / 180.0);
				dirX = cos(angle);
				dirY = sin(angle);
				reset = false;
			}
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

void Ball::Reset()
{
	reset = true;
	dirX = 0;
	dirY = 0;
	posX = ScreenSizeManager::getInstance().GetWidth() / 2;
	posY = ScreenSizeManager::getInstance().GetHeight() / 2;
	ballRect = {(int)posX, (int)posY, BALL_RADIUS, BALL_RADIUS };
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

bool Ball::GetReset()
{
	return reset;
}
