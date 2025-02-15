#pragma once
#include <SDL.h>
#include "Timer.h"
#include "Music.h"

extern SDL_Window* window;

class Ball
{
public:
	static const int BALL_RADIUS = 15;
	static const int BALL_SPEED = 300;

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
	float GetDirY();
	bool GetReset();

	int GetRightScore();
	int GetLeftScore();

private:
	float posX, posY;
	int velocity, additionalSpeed;
	float dirX, dirY;
	bool reset, paddleMoving;
	SDL_Rect ballRect;
	int rightScore, leftScore;
	Mix_Chunk* collisionSound;
	Mix_Chunk* failSound;
};

