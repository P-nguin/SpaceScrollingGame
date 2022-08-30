#include "Animation.h"

Animation::Animation(sf::Texture* texture, int row, int amtPictures, float height, float width, float switchTime)
{
	this->spriteSheet = texture;
	this->row = row;
	this->amtPictures = amtPictures;
	this->height = height;
	this->width = width;
	this->switchTime = switchTime;
	elapsedTime = 0.f;
	curPic = 0;
}

Animation::~Animation() {
	delete this->spriteSheet;
}

void Animation::update(float dt)
{
	
}

void Animation::render()
{
}
