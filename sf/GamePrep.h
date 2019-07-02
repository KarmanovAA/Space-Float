#include "GameObject.cpp"

std::string CurrentMap = "map1.txt";
std::vector<Planet> planets_;

class GamePrep
{
public:
	SpaceShip ss;
	VelocityBar vb_;
	AngleSetter as_;
	Button play_;
	GamePrep(sf::RenderWindow& window);
	Vec2 SetActive(sf::Event& ev, sf::RenderWindow&);
	void Draw(sf::RenderWindow&);
};

