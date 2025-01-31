#pragma once
#include <SDL.h>

class Timer
{
public:
	static Timer& getInstance();
	void tick();
	void stop();

	float GetDeltaTime() const;

private:
	Timer();
	Uint32 lastFrameTime;
	static float deltaTicks;
};

