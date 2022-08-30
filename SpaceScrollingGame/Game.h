#pragma once
#include <map>

#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

#include "Player.h"

class Game
{
private:
	void initWindow();
	void initPlayer();
	void initTextures();

	sf::RenderWindow* window;

	Player* player;

	std::map<std::string, sf::Texture*> textures;

public:
	Game();
	virtual ~Game();

	void run();

	void updatePollEvents();
	void updateInput();
	void update();
	void render();
};