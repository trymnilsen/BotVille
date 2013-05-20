//BotVille is a AI experiment, trying to create a living city

#include <SDL.h>
#include <iostream>
#include "SpriteBuffer.h"
#include "GameLoop.h"

int main(int argc, char* argv[])
{


	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Could not initialize SDL: " << SDL_GetError();
		system("Pause");
		return EXIT_FAILURE;
	}

	SDL_Window *windowPointer(SDL_CreateWindow(
							"Botville",
							SDL_WINDOWPOS_UNDEFINED,
							SDL_WINDOWPOS_UNDEFINED,
							400,400,
							SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL));
	SpriteBuffer SprBuffer(windowPointer);
	//Load the only bmp we use, strip of diffenrent boxes

	GameLoop loop;
	loop.Start();
	while(true)
	{

		loop.SleepUntilUpdate();
	}
	SDL_DestroyWindow(windowPointer);
	system("Pause");
	return EXIT_SUCCESS;
	

}