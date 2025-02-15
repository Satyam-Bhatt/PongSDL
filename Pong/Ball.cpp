#include "Ball.h"
#include "CollisionDetection.h"
#include <stdio.h>
#include <cmath>
#include "ScreenSizeManager.h"
#include <iostream>

Ball::Ball(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
	ballRect = { posX, posY, BALL_RADIUS, BALL_RADIUS };
	velocity = 0;
	dirX = 0;
	dirY = 0;
	reset = true;
	paddleMoving = false;
	rightScore = 0;
	leftScore = 0;
	collisionSound = NULL;
	failSound = NULL;
	additionalSpeed = 0;
}

void Ball::Start()
{
	srand(SDL_GetTicks());

	velocity = BALL_SPEED;
	dirX = 0;
	dirY = 0;

	if (!Music::GetInstance().LoadSFX("Sounds/high.wav", collisionSound))
	{
		printf("Failed to load music!\n");
	}
	if(!Music::GetInstance().LoadSFX("Sounds/fail.mp3", failSound))
	{
		printf("Failed to load music!\n");
	}

	Uint32 flags = SDL_GetWindowFlags(window);

	if (flags & SDL_WINDOW_MAXIMIZED)
	{
		additionalSpeed = 500;
	}
	else
	{
		additionalSpeed = 0;
	}
}

void Ball::Update(SDL_Rect paddle1, SDL_Rect paddle2)
{
	if (dirX == 0 && dirY == 0) return;

	float dt = Timer::getInstance().GetDeltaTime();
	float normalizedDirection = NormalizeDirection(dirX, dirY);
	posX += dirX/normalizedDirection * (velocity + additionalSpeed) * dt;
	posY += dirY/normalizedDirection * (velocity + additionalSpeed) * dt;

	if (CollisionDetection::GetInstance().CheckCollision(ballRect, paddle1) || CollisionDetection::GetInstance().CheckCollision(ballRect, paddle2))
	{
		posX -= dirX / normalizedDirection * (velocity + additionalSpeed) * dt;
		posY -= dirY / normalizedDirection * (velocity + additionalSpeed) * dt;

		if (ballRect.x + BALL_RADIUS - 8 > paddle2.x || ballRect.x  + 8 < paddle1.x + paddle1.w)
		{
			//printf("Collision side\n");

			if (paddleMoving && velocity < 800) velocity = 200 + 200;
			float reflectedAngele = ReflectedAngle(dirX / normalizedDirection, dirY / normalizedDirection);
			dirX = -cos(reflectedAngele);
			dirY = -sin(reflectedAngele);
			if (paddleMoving)
			{
				posX += dirX * (velocity + additionalSpeed) * dt;
				posY += dirY * (velocity + additionalSpeed) * dt + abs(dirY) / dirY * 10;
			}
			else
			{
				posX += dirX * (velocity + additionalSpeed) * dt;
				posY += dirY * (velocity + additionalSpeed) * dt + abs(dirY) / dirY * 10;
			}
		}
		else
		{
			//printf("Collision front\n");

			float reflectedAngele = ReflectedAngle(dirX / normalizedDirection, dirY / normalizedDirection);
			dirX = - cos(reflectedAngele);
			dirY = sin(reflectedAngele);
			posX += dirX  * (velocity + additionalSpeed) * dt + abs(dirX)/dirX * 10;
			posY += dirY  * (velocity + additionalSpeed) * dt;
		}

		Mix_PlayChannel(-1, collisionSound, 0);

	}

	if(posY < 0)
	{
		posY = 0;

		float reflectedAngele = ReflectedAngle(dirX / normalizedDirection, dirY / normalizedDirection);
		dirX = cos(reflectedAngele);
		dirY = -sin(reflectedAngele);
		posX += dirX * (velocity + additionalSpeed) * dt;
		posY += dirY * (velocity + additionalSpeed) * dt;

		Mix_PlayChannel(-1, collisionSound, 0);

	}
	else if(posY > ScreenSizeManager::getInstance().GetHeight() - BALL_RADIUS)
	{
		posY = ScreenSizeManager::getInstance().GetHeight() - BALL_RADIUS;

		float reflectedAngele = ReflectedAngle(dirX / normalizedDirection, dirY / normalizedDirection);
		dirX = cos(reflectedAngele);
		dirY = -sin(reflectedAngele);
		posX += dirX * (velocity + additionalSpeed) * dt;
		posY += dirY * (velocity + additionalSpeed) * dt;

		Mix_PlayChannel(-1, collisionSound, 0);

	}

	//Check if the ball is inside the paddle
	if (CollisionDetection::GetInstance().CheckCollision(ballRect, paddle1) || CollisionDetection::GetInstance().CheckCollision(ballRect, paddle2))
	{
		if (paddle1.x + paddle1.w > posX && paddle1.y + paddle1.h > posY && paddle1.y < posY && paddle1.x < posX)
		{
			float offset = (paddle1.x + paddle1.w) - posX;
			posX += offset + 10;
		}

		if(paddle2.x + paddle2.w > posX && paddle2.y + paddle2.h > posY && paddle2.y < posY && paddle2.x < posX)
		{
			float offset = posX - static_cast<float>(paddle2.x);
			posX = posX - ( offset + 10);
		}
	}

	ballRect = { (int)posX, (int)posY, BALL_RADIUS, BALL_RADIUS };

	if(posX < -1)
	{
		Reset();
		rightScore++;
	}
	else if(posX > ScreenSizeManager::getInstance().GetWidth() + 1)
	{
		Reset();
		leftScore++;
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
				velocity = BALL_SPEED;
				reset = false;
			}
			break;

		case SDLK_UP:
			paddleMoving = true;
			break;

		case SDLK_DOWN:
			paddleMoving = true;
			break;

		case SDLK_w:
			paddleMoving = true;
			break;

		case SDLK_s:
			paddleMoving = true;
			break;
		}
	}
	if (e.type == SDL_KEYUP)
	{
		if(e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_w || e.key.keysym.sym == SDLK_s)
		{
			paddleMoving = false;
		}
	}

	if (e.type == SDL_WINDOWEVENT)
	{
		switch (e.window.event)
		{
		case SDL_WINDOWEVENT_MAXIMIZED:
			additionalSpeed = 500;
			break;

		case SDL_WINDOWEVENT_RESTORED:
			additionalSpeed = 0;
			break;
		}
	}

}

void Ball::Close()
{
	posX = 0;
	posY = 0;
	ballRect = { 0, 0, 0, 0 };

	Mix_FreeChunk(collisionSound);
	collisionSound = NULL;

	Mix_FreeChunk(failSound);
	failSound = NULL;
}

void Ball::Reset()
{
	reset = true;
	dirX = 0;
	dirY = 0;
	posX = ScreenSizeManager::getInstance().GetWidth() / 2;
	posY = ScreenSizeManager::getInstance().GetHeight() / 2;
	ballRect = {(int)posX, (int)posY, BALL_RADIUS, BALL_RADIUS };

	Mix_PlayChannel(-1, failSound, 0);
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

float Ball::GetDirY()
{
	return dirY;
}

bool Ball::GetReset()
{
	return reset;
}

int Ball::GetRightScore()
{
	return rightScore;
}

int Ball::GetLeftScore()
{
	return leftScore;
}
