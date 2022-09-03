#pragma once
#include <iostream>
#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

#include "Animation.h"

class Bullet
{
private:
	sf::Sprite sprite;
	sf::FloatRect hitbox;

	sf::Vector2f dir;
	float movementSpeed;
	float hitBoxReduce;
	
	Animation animation;

	void initHitBox();

public:
	Bullet(sf::Texture* texture, int amtPics, float posX, float posY, float dirX, float dirY, float movementSpeed);
	virtual ~Bullet();

	const sf::FloatRect getBounds() const;
	const sf::Vector2f getPosition() const;

	void setScale(float factor);
	void update(float dt);
	void render(sf::RenderTarget& target);
};