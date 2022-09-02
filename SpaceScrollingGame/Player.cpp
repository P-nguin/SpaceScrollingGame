#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 150.f;
	this->attackCoolDownMax = 0.25f;
	this->attackCoolDown = this->attackCoolDownMax;
	this->damage = 1;
}

void Player::initTexture()
{
	if(!this->texture.loadFromFile("Textures/MainShip/MainShipBases/MainShipFullHealth.png"))
		std::cout << "failed to load mainshipbase" << std::endl;
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->sprite.getTexture()->getSize().x / 2.f, this->sprite.getTexture()->getSize().x / 2.f);
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

const int Player::getDamage()
{
	return this->damage;
}

const float Player::getWidth()
{
	return this->sprite.getTexture()->getSize().x;
}

void Player::setPosition(sf::Vector2f* pos)
{
	this->sprite.setPosition(*pos);
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
