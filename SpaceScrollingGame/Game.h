#pragma once
#include <map>

#include <SFML/Graphics.hpp>
#include <SfML/System.hpp>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game
{
private:
	void initWindow();
	void initPlayer();
	void initTextures();

	sf::RenderWindow* window;

	Player* player;

	sf::Clock mainClock;

	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;
	std::vector<Enemy*> enemies;

	float spawnTimer;
	float spawnTimerMax;

public:
	Game();
	virtual ~Game();

	void run();

	void initVariables();
	void updatePollEvents();
	void updateEnemy(float dt);
	void updateInput(float dt);
	void updateBullets(float dt);
	void update();
	void render();
};