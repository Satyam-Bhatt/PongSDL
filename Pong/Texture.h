#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

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

