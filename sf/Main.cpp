#include "PlayStage.cpp"
extern GamePhase gp;


int main() {
	sf::Music track;
	if (!track.openFromFile("Starry_dreams.ogg"))
		std::cerr << "Musical error";
	track.setLoop(true);
	track.play();
	CurrentMap = "map1.txt";
	sf::Clock timer;
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Space Float");
	sf::Texture bg;
	sf::Sprite bg_spr;
	if (!bg.loadFromFile("Background.png"))
		std::cerr << "Cannot load Background";
	bg_spr.setTexture(bg);
	Menu m(window);
	GamePrep g_prep(window);
	PlayStage ps;
	sf::Event event;
	gp = menu;
	timer.restart();
	bool flag = 1;
	while (window.isOpen()) {
		if (gp == menu) {
			while (window.pollEvent(event))
				m.SetActive(event, window);
			window.clear();
			window.draw(bg_spr);
			m.Draw(window);
			window.display();
		}
		if (gp == prep) {
			if (flag)
				ps.SetVel(Vec2(0,0));
			flag = 0;
			ps.Set();
			while (window.pollEvent(event))
				ps.SetVel(g_prep.SetActive(event, window));
			window.clear();
			window.draw(bg_spr);
			g_prep.Draw(window);
			window.display();
		}
		if (gp == play) {
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Space) {
						gp = prep;
						flag = 1;
						cout << ps.ss_.vel_.abs() << std::endl;
					}
						
					if (event.key.code == sf::Keyboard::Escape)
						gp = menu;
				}
				if (event.type == sf::Event::Closed)
					window.close();
			}
			double dt = timer.getElapsedTime().asSeconds();
			ps.SetActive(event, window, dt);
			window.clear();
			window.draw(bg_spr);
			ps.Draw(window);
			window.display();
		}
	}
	system("pause");
}