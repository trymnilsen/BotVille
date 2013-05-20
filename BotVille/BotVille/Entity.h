#ifndef ENTITY_H
#define ENTITY_H

#include "AppConstants.h"
#include "Vector.h"
#include "SpriteBuffer.h"

class Entity
{
public:
	Entity(std::shared_ptr<SpriteBuffer> SpriteBuffer);
	~Entity();
	void drawEntity();
protected:
	Vector position;
private:
	EntityType unitType;
};
#endif