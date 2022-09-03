#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::FloatRect hitBox;

	float movementSpeed;
	int damage;

	float attackCoolDown;
	float attackCoolDownMax;
	float hitBoxReduce;

	void initVariables();
	void initTexture();
	void initSprite();
	void initHitBox();

public:
	Player();
	virtual ~Player();

	const sf::Vector2f& getPos() const;
	sf::FloatRect getBounds();

	void move(const float dirX, const float dirY, float dt);
	const bool canAttack();
	const int getDamage();
	const float getWidth();

	void setPosition(sf::Vector2f* pos);
	void updateAttack(float dt);
	void update(float dt);
	void render(sf::RenderTarget& target);
};

