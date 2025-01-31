#pragma once
#include <SDL.h>

class CollisionDetection
{
public:
	static CollisionDetection& GetInstance();
	bool CheckCollision(SDL_Rect a, SDL_Rect b);

private:
	CollisionDetection();


};

