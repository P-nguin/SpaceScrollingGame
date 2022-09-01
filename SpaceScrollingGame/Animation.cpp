#include "Animation.h"

Animation::Animation()
{
	switchTime = 0.f; elapsedTime = 0.f;
	height = 0; width = 0;
	row = 0; amtPictures = 0; curPic = 0;
	spriteSheet = NULL;
}

Animation::~Animation()
{
}

void Animation::init(sf::Texture* texture, int row, int amtPictures, int height, int width,
	float switchTime)
{
	this->spriteSheet = texture;
	this->row = row;
	this->amtPictures = amtPictures;
	this->height = height;
	this->width = width;
	this->switchTime = switchTime;
	this->elapsedTime = 0.f;
	this->curPic = 0;
}

sf::IntRect Animation::getFrame()
{
	return sf::IntRect(curPic * width, row * height, width, height);
}

void Animation::update(float dt)
{
	elapsedTime += dt;
	if (elapsedTime >= switchTime) {
		curPic++; elapsedTime -= switchTime;
	}
	if (curPic >= amtPictures) curPic = 0;
}