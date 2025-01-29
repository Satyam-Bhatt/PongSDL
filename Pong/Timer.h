#pragma once
#include <SDL.h>

class Timer
{
public:
	static Timer& getInstance();
	void start();
	void stop();

	float GetDeltaTime();

private:
	Timer();
	Uint32 startTicks;
	static float deltaTicks;
};

