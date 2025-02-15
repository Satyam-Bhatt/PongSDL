#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <string>

class Music
{
public:
	bool LoadMusic(std::string path, Mix_Music*& music);
	bool LoadSFX(std::string path, Mix_Chunk*& sfx);
	static Music& GetInstance() { return instance; }

private:
	Music();
	static Music instance;

};

