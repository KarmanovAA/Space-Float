#include "VelocityBar.h"


VelocityBar::VelocityBar() {
	if (!texture_.loadFromFile("VelBar.png"))
		std::cerr << "Unable to open a texture file" << std::endl;
	slider_ = Slider(texture_, sf::IntRect(0, 0, 100, 100));
	bar_ = sf::Sprite(texture_, sf::IntRect(0, 100, 100, 1000));
	if (!slider_.font.loadFromFile("font.otf"))
		std::cerr << "Unable to open a font file" << std::endl;
	slider_.text.setFont(slider_.font);
	slider_.text.setString("1000");
	slider_.text.setCharacterSize(width_ / 4);
	slider_.text.setFillColor(sf::Color::Yellow);
	slider_.text.setPosition(slider_.getPosition().x + width_, slider_.getPosition().y - width_ / 4);
}

VelocityBar::VelocityBar(sf::RenderWindow& window) {
	if (!texture_.loadFromFile("VelBar.png"))
		std::cerr << "Unable to open a texture file" << std::endl;	
	slider_ = Slider(texture_, sf::IntRect(0, 0, 100, 100));
	bar_ = sf::Sprite(texture_, sf::IntRect(0, 100, 100, 1000));
	Adjust(window);
	if (!slider_.font.loadFromFile("font.otf"))
		std::cerr << "Unable to open a font file" << std::endl;
	slider_.text.setFont(slider_.font);
	slider_.text.setString("1000");
	slider_.text.setCharacterSize(width_ / 4);
	slider_.text.setFillColor(sf::Color::Yellow);
	slider_.text.setPosition(slider_.getPosition().x + width_, slider_.getPosition().y - width_/4);
}

void VelocityBar::Set(sf::RenderWindow& window) {
	if (!texture_.loadFromFile("VelBar.png"))
		std::cerr << "Unable to open a texture file" << std::endl;
	slider_ = Slider(texture_, sf::IntRect(0, 0, 100, 100));
	bar_ = sf::Sprite(texture_, sf::IntRect(0, 100, 100, 1000));
	Adjust(window);
	if (!slider_.font.loadFromFile("font.otf"))
		std::cerr << "Unable to open a font file" << std::endl;
	slider_.text.setFont(slider_.font);
	slider_.text.setString("1000");
	slider_.text.setCharacterSize(width_ / 4);
	slider_.text.setFillColor(sf::Color::Yellow);
	slider_.text.setPosition(slider_.getPosition().x + width_, slider_.getPosition().y - width_ / 4);
}


void VelocityBar::GetAdjustingInfo(double winhorsize, double winvertsize) {
	width_ = winhorsize / 20;
	height_ = winvertsize * 0.5;
	pos_x_ = width_;
	pos_y_ = winvertsize / 6;
}

void VelocityBar::Adjust(sf::RenderWindow& window) {
	GetAdjustingInfo(window.getSize().x, window.getSize().y);
	bar_.setPosition(pos_x_, pos_y_);
	bar_.setScale(width_ / 100, height_ / 1000);
	slider_.setPosition(pos_x_ + width_/2, pos_y_);
	slider_.setScale(width_ / 100, width_ / 100);
}

void VelocityBar::SetActive(sf::Event& event, sf::RenderWindow& window) {
	slider_.SetActive(event, sf::IntRect(3*width_/2, pos_y_, 0, height_));
	if (event.type == sf::Event::Closed)
		window.close();
	if (slider_.velocity == 0) {
		Rick r;
		r.Execute();
	}
}


void VelocityBar::Draw(sf::RenderWindow& window) {
	window.draw(bar_);
	window.draw(slider_);
	window.draw(slider_.text);
}

AngleSetter::AngleSetter() {
	angle = 0;
	if (!texture_.loadFromFile("AngleSetter.png"))
		std::cerr << "Cannot load anglesetter`s texture";
	patch_.setTexture(texture_);
	arrow_.setTexture(texture_);

	patch_.setTextureRect(sf::IntRect(0, 0, 120, 120));
	arrow_.setTextureRect(sf::IntRect(120, 0, 120, 120));

	patch_.setOrigin(60, 60);
	arrow_.setOrigin(60, 60);

	patch_.setPosition(120, 700);
	arrow_.setPosition(120, 700);
}

void AngleSetter::Draw(sf::RenderWindow& rw) {
	rw.draw(patch_);
	rw.draw(arrow_);
}

void AngleSetter::SetActive(sf::Event& ev, sf::RenderWindow& rw) {
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::Up) {
			angle += 1;
		}
		if (ev.key.code == sf::Keyboard::Down) {
			angle -= 1;
		}
		arrow_.setRotation(angle);
	}
}