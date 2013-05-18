#ifndef _SPRITEBUFFER_H_
#define _SPRITEBUFFER_H_

#include <SDL.h>
#include <memory>

class SpriteBuffer
{
public:
	SpriteBuffer(std::shared_ptr<SDL_Window> window);
	~SpriteBuffer();


private:
	std::shared_ptr<SDL_Renderer> Renderer;
};
#endif