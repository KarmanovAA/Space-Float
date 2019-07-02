#include "PlayStage.h"


PlayStage::PlayStage() {
	for (auto& item : planets_) {
		if (item.pt_ == start) {
			ss_.Set(item.r_vec_.getX(), item.r_vec_.getY() - 75);
		}
	}
	ss_.spr_.setRotation(-90);
}

void PlayStage::Set() {
	for (auto& item : planets_) {
		if (item.pt_ == start) {
			ss_.Set(item.r_vec_.getX(), item.r_vec_.getY() - 75);
		}
	}
	ss_.spr_.setRotation(-90);
}


void PlayStage::SetVel(Vec2 init_velocity)
{
	ss_.SetVel(init_velocity.getX(), init_velocity.getY());
}


void PlayStage::Draw(sf::RenderWindow& rw) {
	for (auto& i : planets_) {
		i.Draw(rw);
	}
	ss_.Draw(rw);
}

void PlayStage::SetActive(sf::Event& ev, sf::RenderWindow& rw, double& dt) {
	Vec2 accel;
	for (auto& item : planets_) {
		accel += ss_.CalculateAccel(item);
	}
	ss_.ReCalculateVelocity(accel, dt);
	ss_.ReCalculateCoords(dt);
	ss_.Set(ss_.r_vec_.getX(), ss_.r_vec_.getY());
	for (auto& item : planets_) {
		if ((item.pt_ == start || item.pt_ == ordinary) && (item.r_vec_ - ss_.r_vec_).abs() < 60) {
			gp = menu;
			sf::RenderWindow winwin(sf::VideoMode(500, 500), "You lost....pathetic!");
			sf::Texture tex;
			sf::Sprite spr;
			sf::Font font;
			sf::Text text;
			tex.loadFromFile("Background.png");
			font.loadFromFile("font.otf");
			spr.setTexture(tex);
			text.setFont(font);
			text.setFillColor(sf::Color(253, 180, 53));
			text.setCharacterSize(50);
			text.setString("You Lost");
			text.setPosition(50, 230);
			sf::Event event;
			while (winwin.isOpen()) {
				while (winwin.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						winwin.close();
				}
				winwin.clear();
				winwin.draw(spr);
				winwin.draw(text);
				winwin.display();
			}
		} else 
		if (item.pt_ == finish  && (item.r_vec_ - ss_.r_vec_).abs() < 60) {
			gp = menu;
			sf::RenderWindow winwin(sf::VideoMode(500, 500), "You Won!!!Lucky bastaaaard");
			sf::Texture tex;
			sf::Sprite spr;
			sf::Font font;
			sf::Text text;
			tex.loadFromFile("Background.png");
			font.loadFromFile("font.otf");
			spr.setTexture(tex);
			text.setFont(font);
			text.setFillColor(sf::Color(253, 180, 53));
			text.setCharacterSize(50);
			text.setString("You Won");
			text.setPosition(50, 230);
			sf::Event event;
			while (winwin.isOpen()) {
				while (winwin.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						winwin.close();
				}
				winwin.clear();
				winwin.draw(spr);
				winwin.draw(text);
				winwin.display();
			}
		}
	}
}