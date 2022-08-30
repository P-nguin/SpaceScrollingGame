#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

class Animation
{
private:
	sf::Texture* spriteSheet;
	float switchTime;
	float elapsedTime;
	float height, width;
	int row;
	int amtPictures;
	int curPic = 0;

public:
	Animation(sf::Texture* texture, int row, int amtPictures, float height, float width, float switchTime);
	virtual ~Animation();

	void update(float dt);
	void render();
};

