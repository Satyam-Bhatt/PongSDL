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
	if (e.type == SDL_WINDOWEVENT)
	{
		switch (e.window.event)
		{
			case SDL_WINDOWEVENT_RESIZED:
				width = e.window.data1;
				height = e.window.data2;
		}
	}
}

ScreenSizeManager& ScreenSizeManager::getInstance()
{
	static ScreenSizeManager instance;
	return instance;
}
