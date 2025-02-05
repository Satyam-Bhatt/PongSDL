#pragma once
#include <SDL.h>
#include "Timer.h"

class Ball
{
public:
	static const int BALL_RADIUS = 15;
	static const int BALL_SPEED = 600;

	Ball() = default;
	Ball(int posX, int posY);

	void Start();
	void Render(SDL_Renderer* renderer);
	void Update(SDL_Rect paddle1, SDL_Rect paddle2);
	void HandleEvents(SDL_Event e);
	void Close(); 
	void Reset();
	float NormalizeDirection(float velocityX, float velocityY);
	float ReflectedAngle(float directionX, float directionY);
	SDL_Rect GetBallRect();
	int GetX();
	int GetY();
	bool GetReset();

private:
	float posX, posY;
	int velocity;
	float dirX, dirY;
	bool reset, paddleMoving;
	SDL_Rect ballRect;
};

