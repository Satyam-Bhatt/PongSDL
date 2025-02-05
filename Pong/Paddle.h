#pragma once
#include <SDL.h>

class Paddle
{
public:

	static const int PADDLE_VELOCITY = 300;

	Paddle(int _posX = 0, int _posY = 0, int _width = 0, int _height = 0);
	~Paddle();
	void Close();
	void HandleEvents(SDL_Event e);
	void Render(SDL_Renderer* renderer);
	void Update();
	SDL_Rect GetRect();
	int GetX();
	int GetY();

private:
	SDL_Rect paddleRect;
	int posX, posY, velocity;
};

