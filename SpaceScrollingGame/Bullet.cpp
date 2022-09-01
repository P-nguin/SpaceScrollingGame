#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed)
{
	this->dir.x = dirX;
	this->dir.y = dirY;
	this->movementSpeed = movementSpeed;
	this->sprite.setPosition(posX, posY);
	this->sprite.setTexture(*texture);

	this->animation.init(texture, 0, 4, 32, 32, 0.125f);
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Bullet::update(float dt)
{
	animation.update(dt);
	this->sprite.move(this->movementSpeed * this->dir * dt);
}

void Bullet::render(sf::RenderTarget& target)
{
	this->sprite.setTextureRect(animation.getFrame());
	target.draw(this->sprite);
}
