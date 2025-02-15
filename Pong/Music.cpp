#include "Music.h"

Music Music::instance;

bool Music::LoadMusic(std::string path, Mix_Music*& music)
{
	bool success = true;

	music = Mix_LoadMUS(path.c_str());
	if(music == NULL)
	{
		printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	return success;
}

bool Music::LoadSFX(std::string path, Mix_Chunk*& sfx)
{
	bool success = true;

	sfx = Mix_LoadWAV(path.c_str());
	if(sfx == NULL)
	{
		printf("Failed to load SFX! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	return success;
}

Music::Music() {
}
