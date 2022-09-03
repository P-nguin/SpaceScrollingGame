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
	float width;
	int amtPictures;
	int curPic = 0;

public:
	Animation();
	virtual ~Animation();

	void init(sf::Texture* texture, 
		int amtPictures, 
		float switchTime);

	sf::IntRect getFrame();

	void update(float dt);
};

