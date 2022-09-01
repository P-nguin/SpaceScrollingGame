#pragma once
#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

#include "Animation.h"

class Enemy
{
private:
	sf::Sprite sprite;
	Animation animation;

	int maxHp;
	int health;
	int damage;
	int points;
	float speed;

public:
	Enemy();
	Enemy(sf::Texture* texture, sf::Vector2f pos);
	virtual ~Enemy();

	const sf::FloatRect getBounds() const;
	const int getPoints();
	const int getDamage();
	const int getHealth();

	void setTexture(sf::Texture* texture);

	void update(float dt);
	void render(sf::RenderTarget& target);
};