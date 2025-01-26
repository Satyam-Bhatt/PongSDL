#pragma once
#include <SDL.h>
#include <stdio.h>

class ScreenSizeManager
{
public:
	static ScreenSizeManager& getInstance();

	int GetHeight() const;
	int GetWidth() const;
	void HandleEvents(SDL_Event e);

private:
	ScreenSizeManager();
	~ScreenSizeManager();
	int height, width;
};

