#include "SpriteBuffer.h"

SpriteBuffer::SpriteBuffer(SDL_Window *window)
{
	renderer=std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED));
	SDL_Surface *textureSurface = SDL_LoadBMP("unit.bmp");
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
	SDL_Rect unitTextureSource;
	SDL_Rect unitBufferDestination;
	unitTextureSource.x=0;
	unitTextureSource.y=unitSize*type;
	unitTextureSource.w=unitSize;
	unitTextureSource.h=unitSize;

	unitBufferDestination.x=position.X;
	unitBufferDestination.y=position.Y;
	unitBufferDestination.w=unitSize;
	unitBufferDestination.h=unitSize;

	SDL_RenderCopy(renderer.get(),unitTexture.get(),&unitTextureSource,&unitBufferDestination);
}