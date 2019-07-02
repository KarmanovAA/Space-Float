#include "MapCreator.h"



MapCreator::MapCreator()
{
	if (!Background.loadFromFile("MapCreatorBackground.png"))
		std::cerr << "Cannot load Backgrond texture";
	if (!SettingLine.loadFromFile("SetListSS.png")) 
		std::cerr << "Cannot load button texture";
	Bg.setTexture(Background);
	Bg.setTextureRect(sf::IntRect(0, 0, 1000, 1000));
	Bg.setPosition(0,0);
	SL[0].setTexture(SettingLine);
	SL[0].setTextureRect(sf::IntRect(0, 0, 100, 50));
	SL[0].setPosition(50, 25);
	SL[1].setTexture(SettingLine);
	SL[1].setTextureRect(sf::IntRect(100, 0, 100, 50));
	SL[1].setPosition(200, 25);
	SL[2].setTexture(SettingLine);
	SL[2].setTextureRect(sf::IntRect(200, 0, 100, 50));
	SL[2].setPosition(350, 25);
	SL[3].setTexture(SettingLine);
	SL[3].setTextureRect(sf::IntRect(300, 0, 150, 50));
	SL[3].setPosition(650, 25);
	SL[4].setTexture(SettingLine);
	SL[4].setTextureRect(sf::IntRect(450, 0, 150, 50));
	SL[4].setPosition(800, 25);
}


MapCreator::~MapCreator()
{
}

void MapCreator::Draw(sf::RenderWindow& win) {
	win.draw(Bg);
	for (int i = 0; i < 5; i++) {
		win.draw(SL[i]);
	}
}

int main() {
	MapCreator m;
	sf::Texture t;
	t.loadFromFile("MapCreatorBackground.png");
	sf::Sprite s;
	s.setTexture(t);
	sf::RenderWindow win(sf::VideoMode(1000, 1000), "My window");
	while (win.isOpen()) {
		win.clear();
		m.Draw(win);
		win.display();
	}
	return 0;
}