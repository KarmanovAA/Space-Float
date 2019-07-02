#pragma once
#include "Menu.cpp"

class PlayStage
{
public:
	SpaceShip ss_;

	PlayStage();
	void Set();
	void SetVel(Vec2 init_velocity);
	void SetActive(sf::Event& ev, sf::RenderWindow& rw, double& dt);
	void Draw(sf::RenderWindow& rw);
};

