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

	sf::Vector2f dir;
	float movementSpeed;
	
	Animation animation;

public:
	Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed);
	virtual ~Bullet();

	const sf::FloatRect getBounds() const;

	void update(float dt);
	void render(sf::RenderTarget& target);
};