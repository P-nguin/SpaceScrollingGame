#pragma once
#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	void initTexture();
	void initSprite();

public:
	Player();
	~Player();

	void update();
	void render(sf::RenderTarget& target);
};

