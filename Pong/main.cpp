#include <stdio.h>
#include <SDL.h>
#include "GameState.h"

GameState* currentState = NULL;
GameState* nextstate = NULL;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool init();
void close();
void setNextState(GameState* state);
void changeState();

int main(int argc, char* args[])
{
	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);

	printf("Hello World");
	return 0;
}