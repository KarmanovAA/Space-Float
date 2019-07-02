#include "Slider.cpp"


class VelocityBar {
public:
	sf::Texture texture_;
	sf::Sprite bar_;
	Slider slider_;
	double width_ = 100, height_ = 100, pos_x_, pos_y_; // Bar rectangle

	VelocityBar();
	VelocityBar(sf::RenderWindow& window);
	void Set(sf::RenderWindow& window);
	void GetAdjustingInfo(double winhorsize, double winvertsize);
	void Adjust(sf::RenderWindow&);
	void SetActive(sf::Event&, sf::RenderWindow& window);
	void Draw(sf::RenderWindow&);
};

class AngleSetter {
public:
	sf::Texture texture_;
	sf::Sprite patch_, arrow_;
	double angle;

	AngleSetter();
	void SetActive(sf::Event& ev, sf::RenderWindow& rw);
	void Draw(sf::RenderWindow& rw);
};