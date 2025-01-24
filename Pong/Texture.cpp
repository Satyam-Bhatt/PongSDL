#include "Texture.h"

Texture::Texture()
{
	texture = NULL;
	width = 0;
	height = 0;
}

Texture::~Texture()
{
	Free();
}

bool Texture::LoadFromFile(std::string path, SDL_Renderer* renderer)
{
	bool success = true;

	//Get rid of preexisting texture
	Free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Loaded Texture
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		success = false;
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			success = false;
		}
		else
		{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	if(success)
	{
		texture = newTexture;
	}

	return success;
}

void Texture::Render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip)
{
	if (texture != NULL)
	{
		SDL_Rect renderQuad = { x, y, width, height };

		if (clip != NULL)
		{
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}

		SDL_RenderCopy(renderer, texture, clip, &renderQuad);
	}
}

bool Texture::LoadText(TTF_Font* font, std::string fontPath, std::string text, SDL_Color textColor, int fontSize, SDL_Renderer* renderer)
{
	bool success = true;

	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (font == NULL)
	{
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		Free();

		SDL_Texture* newTexture = NULL;

		//Loaded texture
		SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
		if (textSurface == NULL)
		{
			printf("Unable to render text surface! SDL_ttf Error: &s\n", TTF_GetError());
			success = false;
		}
		else
		{
			newTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
			if (newTexture == NULL)
			{
				printf("Unable to create texture from text! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				width = textSurface->w;
				height = textSurface->h;
			}

			SDL_FreeSurface(textSurface);
		}

		if (success)
		{
			texture = newTexture;
		}
	}
	return success;
}

void Texture::Free()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

int Texture::GetWidth()
{
	return width;
}

int Texture::GetHeight()
{
	return height;
}
