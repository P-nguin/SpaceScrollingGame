#include "Player.h"

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

	this->sprite.scale(2.6f, 2.6f);

	this->movementSpeed = 10.f;
}

Player::~Player()
{
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
