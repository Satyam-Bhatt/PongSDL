#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include "ScreenSizeManager.h"

class Texture
{
public:
	//Initializes variables
	Texture();

	//Deallocates memory
	~Texture();

	//Loads image at specified path
	bool LoadFromFile(std::string path, SDL_Renderer* renderer);

	//Render texture to the screen
	void Render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip = NULL);

	//Render texture to full screen
	void RenderFullScreen(SDL_Renderer* renderer, SDL_Rect* clip = NULL);

	//Render Text
	bool LoadText(TTF_Font* font, std::string fontPath, std::string text, SDL_Color textColor, int fontSize, SDL_Renderer* renderer);

	//Accessor functions
	int GetWidth();
	int GetHeight();

	//Close texture
	void Free();

private:
	//Actual texture in which info will be stored
	SDL_Texture* texture;

	//Image dimensions
	int width;
	int height;
};

