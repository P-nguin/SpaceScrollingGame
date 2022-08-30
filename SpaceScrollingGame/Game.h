#pragma once
#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void run();

	void update();
	void render();

private:
	void initWindow();

	sf::RenderWindow* window;
};