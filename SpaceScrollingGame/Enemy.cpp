#include "Enemy.h"

Enemy::Enemy()
{
	maxHp = 3; health = maxHp;
	damage = 1; points = 10;
	speed = 100.f;
}

Enemy::Enemy(sf::Texture* texture, sf::Vector2f pos)
{
	sprite.setTexture(*texture);
	sprite.setPosition(pos);

	maxHp = 3;
	health = maxHp;
	damage = 1;
	points = 10;
	speed = 100.f;
}

Enemy::~Enemy()
{
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int Enemy::getPoints()
{
	return this->points;
}

const int Enemy::getDamage()
{
	return this->damage;
}

const int Enemy::getHealth()
{
	return this->health;
}

void Enemy::setTexture(sf::Texture* texture)
{
	this->sprite.setTexture(*texture);
}

void Enemy::update(float dt)
{
	this->sprite.move(0.f, this->speed * dt);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
