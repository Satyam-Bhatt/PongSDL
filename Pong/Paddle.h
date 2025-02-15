#pragma once
#include <SDL.h>
#include "ScreenSizeManager.h"

extern SDL_Window* window;

class Paddle
{
public:

	static const int PADDLE_VELOCITY = 200;

	Paddle(int _posX = 0, int _posY = 0, int _width = 0, int _height = 0);
	~Paddle();
	void Start();
	void Close();
	virtual void HandleEvents(SDL_Event e);
	void Render(SDL_Renderer* renderer);
	virtual void Update();
	SDL_Rect GetRect();
	float GetX();
	float GetY();

protected:
	SDL_Rect paddleRect;
	float posX, posY;
	int velocity;
	int additionalSpeed = 0;
	static int aiSpeedIncrease;
};

