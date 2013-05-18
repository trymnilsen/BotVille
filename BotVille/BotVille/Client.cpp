//BotVille is a AI experiment, trying to create a living city

#include <SDL.h>
#include <iostream>
#include "SpriteBuffer.h"
int main(int argc, char* argv[])
{


	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Could not initialize SDL: " << SDL_GetError();
		system("Pause");
		return EXIT_FAILURE;
	}

	SpriteBuffer spriteBuffer();

	system("Pause");
	return EXIT_SUCCESS;
	

}