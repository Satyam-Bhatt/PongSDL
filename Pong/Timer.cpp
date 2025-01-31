#include "Timer.h"
#include <stdio.h>

float Timer::deltaTicks = 0.0;

Timer::Timer()
{
	lastFrameTime = SDL_GetTicks();
}

Timer& Timer::getInstance()
{
	static Timer instance;
	return instance;
}

void Timer::tick()
{
	deltaTicks = (SDL_GetTicks() - lastFrameTime) / 1000.0f;
	lastFrameTime = SDL_GetTicks();
}

void Timer::stop()
{
	lastFrameTime = 0;
}

float Timer::GetDeltaTime() const
{
	return deltaTicks;
}
