#include "ScreenSizeManager.h"

ScreenSizeManager::ScreenSizeManager()
{
    height = 480;
	width = 640;
}

ScreenSizeManager::~ScreenSizeManager()
{
	// No need to delete instance as it is not a pointer
}

int ScreenSizeManager::GetHeight() const
{
	return height;
}

int ScreenSizeManager::GetWidth() const
{
	return width;
}

void ScreenSizeManager::HandleEvents(SDL_Event e)
{
	printf("yoyo");
}

ScreenSizeManager& ScreenSizeManager::getInstance()
{
	static ScreenSizeManager instance;
	return instance;
}
