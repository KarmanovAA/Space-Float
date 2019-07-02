#include "GamePrep.h"


GamePrep::GamePrep(sf::RenderWindow& window) {
	play_.SetButton("Button.png", sf::IntRect(0, 0, 200, 50), sf::Vector2f(10,10), "Play");
	vb_.Set(window);
	LoadPlanets(planets_, CurrentMap);
	for (auto& item : planets_)
		if (item.pt_ == start)
			ss.spr_.setPosition(item.r_vec_.getX(), item.r_vec_.getY() - 75);
	ss.spr_.setRotation(-90);
}

Vec2 GamePrep::SetActive(sf::Event& ev, sf::RenderWindow& rw) {
	Vec2 speed(1,0);
	vb_.SetActive(ev, rw);
	as_.SetActive(ev, rw);
	speed.normalize();
	speed = speed * vb_.slider_.velocity / 7000;
	speed.set(speed.abs()*cos(as_.angle*3.14159 / 180), speed.abs()*sin(as_.angle*3.14159/180));
	if (play_.Was_Pressed(ev) || (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Enter)) {
		gp = play;
	}
	return speed;
}
void GamePrep::Draw(sf::RenderWindow& rw) {
	for (int i = 0; i < planets_.size();i++) {
		planets_[i].Draw(rw);
	}
	vb_.Draw(rw);
	as_.Draw(rw);
	play_.Draw(rw);
	//std::cout << ss.spr_.getPosition().x << std::endl;
	rw.draw(ss.spr_);
}


