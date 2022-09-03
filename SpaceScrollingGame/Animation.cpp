#include "Animation.h"

Animation::Animation()
{
	this->switchTime = 0.f; this->elapsedTime = 0.f;
	this->amtPictures = 0; this->curPic = 0;
	this->spriteSheet = NULL; this->width = 0;
}

Animation::~Animation()
{
}

void Animation::init(sf::Texture* texture, int amtPictures,
	float switchTime)
{
	this->spriteSheet = texture;
	this->amtPictures = amtPictures;
	this->switchTime = switchTime;
	this->elapsedTime = 0.f;
	this->width = this->spriteSheet->getSize().x / (float)amtPictures;
	this->curPic = 0;
}

sf::IntRect Animation::getFrame()
{
	return sf::IntRect(curPic * width, 0, width, spriteSheet->getSize().y);
}

void Animation::update(float dt)
{
	elapsedTime += dt;
	if (elapsedTime >= switchTime) {
		curPic++; elapsedTime -= switchTime;
	}
	if (curPic >= amtPictures) curPic = 0;
}