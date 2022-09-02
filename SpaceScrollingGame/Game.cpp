#include "Game.h"

#include "Animation.h"

Game::Game() 
{
	this->initWindow();
	this->initTextures();
	this->initPlayer();
	this->initVariables();
}

Game::~Game() 
{
	delete this->window;
	delete this->player;

	for (auto& i : this->textures) {
		delete i.second;
	}

	for (auto* i : this->bullets) {
		delete i;
	}
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}

void Game::initVariables()
{
	spawnTimerMax = 1.0f;
	spawnTimer = spawnTimerMax;
}

void Game::updateEnemy(float dt)
{
	if (spawnTimer < spawnTimerMax) {
		spawnTimer += dt;
	}
	else {
		spawnTimer -= spawnTimerMax;
		enemies.push_back(new Enemy(this->textures["SCOUT"], sf::Vector2f(rand() % 600, -60)));
	}

	int cnt = 0;
	for (auto* e : this->enemies) {
		e->update(dt);

		if (e->getPosition().y >= this->window->getSize().y + 40) {
			delete this->enemies[cnt];
			enemies.erase(enemies.begin() + cnt);
			cnt--;
		}
		cnt++;
	}
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e)) {
		if (e.type == sf::Event::Closed || e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateInput(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f, dt);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack()) {
		this->bullets.push_back(new Bullet(this->textures["BULLET"], 
			this->player->getPos().x + this->player->getWidth()/2 + this->textures["BULLET"]->getSize().x/2, this->player->getPos().y,
			0.f, -1.f, 300.f));
	}
}

void Game::updateBullets(float dt)
{
	int cnt = 0;
	for (auto* b : this->bullets) {
		b->update(dt);

		if (b->getBounds().top + b->getBounds().height < 0.f) {
			delete this->bullets[cnt];
			this->bullets.erase(this->bullets.begin() + cnt);
			if (cnt == 0) continue;
			cnt--;
			continue;
		}

		int cnt2 = 0;
		for (auto* e : enemies) {
			if (b->getBounds().intersects(e->getBounds())) {
				delete this->bullets[cnt];
				this->bullets.erase(this->bullets.begin() + cnt);
				if (e->takeDamage(this->player->getDamage())) {
					delete this->enemies[cnt2];
					this->enemies.erase(this->enemies.begin() + cnt2);
				}
				cnt--;
				break;
			}
			cnt2++;
		}

		cnt++;
	}
}

void Game::update()
{
	float dt = mainClock.restart().asSeconds();
	this->updatePollEvents();
	this->updateInput(dt);
	this->player->update(dt);
	this->updateEnemy(dt);
	this->updateBullets(dt);
}

void Game::render()
{
	window->clear();

	this->player->render(*this->window);

	for (auto* b : this->bullets) {
		b->render(*this->window);
	}

	for (auto* e : this->enemies) {
		e->render(*this->window);
	}

	window->display();
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
	this->player = new Player();
	this->player->setPosition(new sf::Vector2f(this->window->getSize().x/2, this->window->getSize().y / 2));
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/MainShip/MainshipProjectiles/Bullet.png");

	this->textures["SCOUT"] = new sf::Texture();
	this->textures["SCOUT"]->loadFromFile("Textures/Nairan/Base/Scout.png");
}
