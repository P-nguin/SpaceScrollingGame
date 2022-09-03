#include "Bullet.h"

void Bullet::initHitBox()
{
	hitbox.width = this->sprite.getTexture()->getSize().x/4.f - hitBoxReduce;
	hitbox.height = this->sprite.getTexture()->getSize().y - hitBoxReduce;
	hitbox.top = this->sprite.getPosition().y - this->hitbox.height / 2.f;
	hitbox.left = this->sprite.getPosition().x - this->hitbox.width / 2.f;
}

Bullet::Bullet(sf::Texture* texture, int amtPics, float posX, float posY, float dirX, float dirY, float movementSpeed)
{
	this->dir.x = dirX;
	this->dir.y = dirY;
	this->movementSpeed = movementSpeed;
	this->hitBoxReduce = 18.f;
	this->sprite.setOrigin(texture->getSize().x / (float)amtPics / 2.f, texture->getSize().y / 2.f);
	this->sprite.setPosition(posX, posY);
	this->sprite.setTexture(*texture);

	this->animation.init(texture, amtPics, 0.125f);
	initHitBox();
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return this->hitbox;
}

const sf::Vector2f Bullet::getPosition() const
{
	return this->sprite.getPosition();
}

void Bullet::setScale(float factor)
{
	this->sprite.setScale(factor, factor);
}

void Bullet::update(float dt)
{
	animation.update(dt);
	this->sprite.move(this->movementSpeed * this->dir * dt);
	this->hitbox.top += this->movementSpeed * this->dir.y * dt;
}

void Bullet::render(sf::RenderTarget& target)
{
	this->sprite.setTextureRect(animation.getFrame());
	target.draw(this->sprite);
}
