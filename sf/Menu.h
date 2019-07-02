#pragma once
#include "GamePrep.cpp"

class Menu
{
public:
	Menu(sf::RenderWindow& win);
	void SetActive(sf::Event& ev, sf::RenderWindow& win);
	void Draw(sf::RenderWindow& win);

	Button play_;
	Button create_map_;
	Button exit_;
	sf::Texture Bg_texture_;
	sf::Sprite Bg_sprite_;
	sf::Text headline_;
	sf::Font font_;
};

