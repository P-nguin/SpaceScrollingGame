#include "Enemy.h"

void Enemy::initHitBox()
{
	hitbox.top = this->sprite.getPosition().y - this->sprite.getTexture()->getSize().y / 2.f;
	hitbox.left = this->sprite.getPosition().x - this->sprite.getTexture()->getSize().x / 2.f;
	hitbox.width = this->sprite.getTexture()->getSize().x;
	hitbox.height = this->sprite.getTexture()->getSize().y;
}

Enemy::Enemy()
{
	maxHp = 3; health = maxHp;
	damage = 1; points = 10;
	speed = 100.f;
	sprite.setOrigin(this->sprite.getTexture()->getSize().x / 2.f, this->sprite.getTexture()->getSize().y / 2.f);
}

Enemy::Enemy(sf::Texture* texture, sf::Vector2f pos)
{
	sprite.setTexture(*texture);
	sprite.setPosition(pos);

	maxHp = 3;
	health = maxHp;
	damage = 1;
	points = 10;
	speed = 60.f;
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

bool Enemy::takeDamage(int dmg)
{
	this->health -= dmg;
	if (health <= 0) return true;
	return false;
}

sf::Vector2f Enemy::getPosition()
{
	return this->sprite.getPosition();
}

void Enemy::update(float dt)
{
	this->sprite.move(0.f, this->speed * dt);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
