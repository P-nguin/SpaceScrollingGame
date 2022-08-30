#include "Game.h"

Game::Game() 
{
	this->initWindow();
}

Game::~Game() 
{
	delete this->window;
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->update();

		this->render();
	}
}

void Game::update()
{

}

void Game::render()
{
	window->clear();



	window->display();
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Game", sf::Style::Close | sf::Style::Titlebar);
}
