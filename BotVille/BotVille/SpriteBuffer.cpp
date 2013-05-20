#include "SpriteBuffer.h"

SpriteBuffer::SpriteBuffer(SDL_Window *window)
{
	renderer=std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED));
	SDL_Surface *textureSurface = SDL_LoadBMP("units.bmp");
	unitTexture=std::shared_ptr<SDL_Texture>(
				SDL_CreateTextureFromSurface(
									renderer.get(),
									textureSurface));
	SDL_FreeSurface(textureSurface);
}

SpriteBuffer::~SpriteBuffer()
{
	SDL_DestroyRenderer(renderer.get());
	renderer.reset();
}
void SpriteBuffer::DrawUnit(Vector position, EntityType type)
{

}