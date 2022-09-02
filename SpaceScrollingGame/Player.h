#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;
	int damage;

	float attackCoolDown;
	float attackCoolDownMax;

	void initVariables();
	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	const sf::Vector2f& getPos() const;

	void move(const float dirX, const float dirY, float dt);
	const bool canAttack();
	const int getDamage();
	const float getWidth();

	void setPosition(sf::Vector2f* pos);
	void updateAttack(float dt);
	void update(float dt);
	void render(sf::RenderTarget& target);
};

