#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 150.f;
	this->attackCoolDownMax = 0.5f;
	this->attackCoolDown = this->attackCoolDownMax;
}

void Player::initTexture()
{
	if(!this->texture.loadFromFile("Textures/MainShip/MainShipBases/MainShipFullHealth.png"))
		std::cout << "failed to load mainshipbase" << std::endl;
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
	this->initVariables();

	this->sprite.scale(2.6f, 2.6f);
}

Player::~Player()
{
}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

void Player::move(const float dirX, const float dirY, float dt)
{
	this->sprite.move(this->movementSpeed * dirX * dt, this->movementSpeed * dirY * dt);
}

const bool Player::canAttack()
{
	if (this->attackCoolDown >= this->attackCoolDownMax) {
		this->attackCoolDown = attackCoolDownMax - attackCoolDown;
		return true;
	}
		
	return false;
}

void Player::updateAttack(float dt)
{
	if (this->attackCoolDown < this->attackCoolDownMax)
		this->attackCoolDown += dt;
}

void Player::update(float dt)
{
	updateAttack(dt);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
