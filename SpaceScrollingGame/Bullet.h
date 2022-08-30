#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

class Bullet
{
private:
	sf::Sprite sprite;

	sf::Vector2f dir;
	float movementSpeed;

public:
	Bullet();
	Bullet(sf::Texture texture, float dirX, float dirY, float movementSpeed);
	virtual ~Bullet();

	void update();
	void render(sf::RenderTarget* target);
};

