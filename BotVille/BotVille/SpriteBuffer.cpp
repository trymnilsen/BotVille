#include "SpriteBuffer.h"

SpriteBuffer::SpriteBuffer(std::shared_ptr<SDL_Window> window)
{
	Renderer=std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(window.get(),-1,SDL_RENDERER_ACCELERATED));
}

SpriteBuffer::~SpriteBuffer()
{
	
}