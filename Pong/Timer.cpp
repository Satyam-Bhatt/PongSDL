#include "Timer.h"
#include <stdio.h>

float Timer::deltaTicks = 0.0;

Timer::Timer()
{
	startTicks = 0;
}

Timer& Timer::getInstance()
{
	static Timer instance;
	return instance;
}

void Timer::start()
{
	deltaTicks = (SDL_GetTicks() - startTicks) / 1000.0f;
	startTicks = SDL_GetTicks();
}

void Timer::stop()
{
	startTicks = 0;
}

float Timer::GetDeltaTime()
{
	return deltaTicks;
}
