#pragma once
#include "Rick.cpp"

enum GamePhase { menu, prep, play };

GamePhase gp;

class Button
{
public:
	sf::FloatRect rec_;
	sf::Sprite spr_;
	sf::Texture tex_;
	sf::Text but_text_;
	bool is_pressed_ = false;

	Button();
	Button(std::string texture_filename, sf::IntRect texture_rect, sf::Vector2f pos, std::string str);

	void SetButton(std::string texture_filename, sf::IntRect texture_rect, sf::Vector2f pos, std::string str);
	bool Was_Pressed(sf::Event& event);
	void Draw(sf::RenderWindow& wind);
private:
	sf::Font font;
	
};

class MovSprite: public sf::Sprite
{
public:
	MovSprite() : width_(0), height_(0){}
	MovSprite(sf::Texture&, sf::IntRect); 
	MovSprite(sf::Texture&);
	void SetActive(sf::Event& event);
	void Rescale(float widfactor, float heightfactor);
	
	sf::Sprite sprite_;
	double width_ , height_ ;
protected:
	double PressedX_ = -1;
	double PressedY_ = -1;
	bool MouseStatus_ = false;
	bool ControlGained = false;
};

