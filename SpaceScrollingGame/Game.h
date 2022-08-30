#pragma once
#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>
#include <SFML/Window.hpp>

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