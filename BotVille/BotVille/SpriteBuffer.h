#ifndef SPRITEBUFFER_H
#define SPRITEBUFFER_H

#include <SDL.h>
#include <memory>
#include "Vector.h"
#include "AppConstants.h"

class SpriteBuffer
{
public:
	SpriteBuffer(SDL_Window *window);
	~SpriteBuffer();
	void DrawUnit(Vector position, EntityType type);

private:
	std::shared_ptr<SDL_Renderer> renderer;
	std::shared_ptr<SDL_Texture> unitTexture;
};
#endif