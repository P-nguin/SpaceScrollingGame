#pragma once
#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

#include "Animation.h"

class Enemy
{
private:
	sf::Sprite sprite;
	sf::FloatRect hitbox;
	Animation animation;

	int maxHp;
	int health;
	int damage;
	int points;
	float speed;

	void initHitBox();

public:
	Enemy();
	Enemy(sf::Texture* texture, sf::Vector2f pos);
	virtual ~Enemy();

	const sf::FloatRect getBounds() const;
	const int getPoints();
	const int getDamage();
	const int getHealth();

	bool takeDamage(int dmg);
	sf::Vector2f getPosition();

	void update(float dt);
	void render(sf::RenderTarget& target);
};