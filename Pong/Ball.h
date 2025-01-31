#pragma once
#include <SDL.h>
#include "Timer.h"

class Ball
{
public:
	static const int BALL_RADIUS = 15;
	static const int BALL_SPEED = 200;

	Ball() = default;
	Ball(int posX, int posY);

	void Start();
	void Render(SDL_Renderer* renderer);
	void Update();
	void HandleEvents(SDL_Event e);
	void Close();
	void CollidedWithPaddle(SDL_Rect paddle1, SDL_Rect paddle2);
	SDL_Rect GetBallRect();
	int GetX();
	int GetY();

private:
	float posX, posY;
	int velocityX, velocityY;
	SDL_Rect ballRect;
};

