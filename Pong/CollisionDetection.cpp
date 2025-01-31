#include "CollisionDetection.h"

CollisionDetection::CollisionDetection()
{
}

CollisionDetection& CollisionDetection::GetInstance()
{
	static CollisionDetection instance;
	return instance;
}

bool CollisionDetection::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	//if(SDL_HasIntersection(&a, &b))
	//	return true;
	//return false;

	int leftA = a.x;
	int rightA = a.x + a.w;
	int topA = a.y;
	int bottomA = a.y + a.h;

	int leftB = b.x;
	int rightB = b.x + b.w;
	int topB = b.y;
	int bottomB = b.y + b.h;

	if(leftA >= rightB)
		return false;
	if(rightA <= leftB)
		return false;
	if(topA >= bottomB)
		return false;
	if(bottomA <= topB)
		return false;
	return true;
}
