#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture& texture, float dirX, float dirY, float movementSpeed)
{
	this->sprite.setTexture(texture);
	this->dir.x = dirX;
	this->dir.y = dirY;
	this->movementSpeed = movementSpeed;
}

Bullet::~Bullet()
{
}

void Bullet::update()
{
	this->sprite.move(this->movementSpeed * this->dir);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
