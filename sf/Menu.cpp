#include "Menu.h"

extern GamePhase gp;

Menu::Menu(sf::RenderWindow& win)
{
	if (!Bg_texture_.loadFromFile("Background.png"))
		std::cerr << "Cannot open texture file";
	if (!font_.loadFromFile("font.otf"))
		std::cerr << "Cannot open font file";

	headline_.setFont(font_);
	headline_.setPosition(win.getSize().x / 4, win.getSize().y / 10);
	headline_.setString("Space Float");
	headline_.setCharacterSize(win.getSize().x / 22);
	headline_.setFillColor(sf::Color(253, 180, 53));

	Bg_sprite_.setTexture(Bg_texture_);
	play_.SetButton("Button.png", sf::IntRect(0, 0, 200, 50), sf::Vector2f(win.getSize().x / 2 - 100, win.getSize().y / 2), "Play");
	create_map_.SetButton("Button.png", sf::IntRect(0, 0, 200, 50), sf::Vector2f(win.getSize().x / 2 - 100, win.getSize().y / 2 + 100), "Create map");
	exit_.SetButton("Button.png", sf::IntRect(0, 0, 200, 50), sf::Vector2f(win.getSize().x / 2 - 100, win.getSize().y - 200), "Exit");
}

void Menu::SetActive(sf::Event& ev, sf::RenderWindow& win) {
	if (play_.Was_Pressed(ev)) {
		gp = prep;
	}
	if (create_map_.Was_Pressed(ev)) {
		//Switch_To();
		std::cout << "CM";
	}
	if (exit_.Was_Pressed(ev) || ev.type == sf::Event::Closed) {
		win.close();
	}
}

void Menu::Draw(sf::RenderWindow& win) {
	win.draw(Bg_sprite_);
	win.draw(headline_);
	play_.Draw(win);
	//create_map_.Draw(win);
	exit_.Draw(win);
}

//int main() {
//	sf::RenderWindow win(sf::VideoMode(1600, 900), "MyGame"/*, sf::Style::Fullscreen*/);
//	Menu m(win);
//	sf::Event ev;
//	while (win.isOpen()) {
//		win.clear();
//		while (win.pollEvent(ev)) {
//			m.SetActive(ev, win);
//		}
//		//m.Draw(win);
//		win.display();
//	}
//	return 0;
//}