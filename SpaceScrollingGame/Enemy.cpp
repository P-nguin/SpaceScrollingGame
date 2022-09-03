#include "Enemy.h"

void Enemy::initHitBox()
{
	hitbox.width = this->sprite.getTexture()->getSize().x - hitBoxReduce;
	hitbox.height = this->sprite.getTexture()->getSize().y - hitBoxReduce;
	hitbox.top = this->sprite.getPosition().y - this->hitbox.height/2.f;
	hitbox.left = this->sprite.getPosition().x - this->hitbox.width/2.f;
}

Enemy::Enemy()
{
	maxHp = 3; health = maxHp;
	damage = 1; points = 10;
	hitBoxReduce = 21;
	speed = 100.f;
	attackCoolDownMax = 4.0f; attackCoolDown = attackCoolDownMax;
	sprite.setOrigin(this->sprite.getTexture()->getSize().x / 2.f, this->sprite.getTexture()->getSize().y / 2.f);
	initHitBox();
}

Enemy::Enemy(sf::Texture* texture, sf::Vector2f pos)
{
	maxHp = 3;
	health = maxHp;
	damage = 1;
	points = 10;
	speed = 50.f;
	hitBoxReduce = 40;
	attackCoolDownMax = 4.f;  attackCoolDown = attackCoolDownMax;
	sprite.setTexture(*texture);
	sprite.setPosition(pos);
	sprite.setOrigin(this->sprite.getTexture()->getSize().x / 2.f, this->sprite.getTexture()->getSize().y / 2.f);
	initHitBox();
}

Enemy::~Enemy()
{
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->hitbox;
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

bool Enemy::canAttack()
{
	if (this->attackCoolDown >= this->attackCoolDownMax) {
		this->attackCoolDown -= attackCoolDown;
		return true;
	}

	return false;
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
	this->hitbox.top += this->speed * dt;

	if (attackCoolDown < attackCoolDownMax)
		attackCoolDown += dt;
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
