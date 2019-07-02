#include "MovSprite.h"


bool IsWithinBoundaries(double x, double y, double boundleft,
	double boundright, double boundtop, double boundbottom)
{
	if (x >= boundleft && x <= boundright && y >= boundtop && y <= boundbottom)
		return true;
	return false;
}


Button::Button() {
	rec_ = sf::FloatRect(0, 0, 0, 0);
	//loading font
	if (!font.loadFromFile("font.otf"))
		std::cerr << "Cannot load a font";
}

Button::Button(std::string texture_filename, sf::IntRect texture_rect,sf::Vector2f pos, std::string str) {
	//loading texture
	if (!tex_.loadFromFile(texture_filename))
		std::cerr << "Cannot load a texture";
	//loading font
	if (!font.loadFromFile("font.otf"))
		std::cerr << "Cannot load a font";
	//Defining button position and outlook
	spr_.setTexture(tex_);
	spr_.setTextureRect(texture_rect);
	spr_.setPosition(pos);
	//Setting info on position
	rec_.left = pos.x;
	rec_.top = pos.y;
	rec_.width = texture_rect.width;
	rec_.height = texture_rect.height;
	//Dealing with text
	but_text_.setFont(font);
	but_text_.setString(str);
	but_text_.setCharacterSize(rec_.width / str.length() / 2);
	but_text_.setFillColor(sf::Color(253, 180, 53));
	but_text_.setPosition(rec_.left + rec_.width / 4, rec_.top + rec_.height / 4);

}


void Button::Draw(sf::RenderWindow& wind) {
	wind.draw(spr_);
	wind.draw(but_text_);
}


void Button::SetButton(std::string texture_filename, sf::IntRect texture_rect, sf::Vector2f pos, std::string str) {
	//loading texture
	if (!tex_.loadFromFile(texture_filename))
		std::cerr << "Cannot load a texture";
	//loading font
	if (!font.loadFromFile("font.otf"))
		std::cerr << "Cannot load a font";
	//Defining button position and outlook
	spr_.setTexture(tex_);
	spr_.setTextureRect(texture_rect);
	spr_.setPosition(pos);
	//Setting info on position
	rec_.left = pos.x;
	rec_.top = pos.y;
	rec_.width = texture_rect.width;
	rec_.height = texture_rect.height;
	//Dealing with text
	but_text_.setFont(font);
	but_text_.setString(str);
	but_text_.setCharacterSize(rec_.width / str.length() / 2);
	but_text_.setFillColor(sf::Color(253, 180, 53));
	but_text_.setPosition(rec_.left + rec_.width / 4, rec_.top + rec_.height / 4);
}

bool Button::Was_Pressed(sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed && 
		IsWithinBoundaries(event.mouseButton.x, event.mouseButton.y, rec_.left, rec_.left + rec_.width, rec_.top, rec_.top + rec_.height))
	{
		if (is_pressed_) 
		{
			is_pressed_ = false;
			spr_.setColor(sf::Color::White);
		}
		else
		{
			is_pressed_ = true;
			spr_.setColor(sf::Color(100, 100, 100));
		}
		
		return true;
	}
	return false;
}

MovSprite::MovSprite(sf::Texture& Tex, sf::IntRect Rec){
	this->setTexture(Tex);
	this->setTextureRect(Rec);
	width_ = Rec.width;
	height_ = Rec.height;
	this->setOrigin(width_ / 2, height_ / 2);
}

MovSprite::MovSprite(sf::Texture& Tex) {
	this->setTexture(Tex);
	width_ = Tex.getSize().x;
	height_ = Tex.getSize().y;
	this->setOrigin(width_ / 2, height_ / 2);
}

void MovSprite::Rescale(float widfactor, float heightfactor) {
	width_ *= widfactor;
	height_ *= heightfactor;
	setScale(widfactor, heightfactor);
}

void MovSprite::SetActive(sf::Event& event) {
	double x = event.mouseMove.x;
	double y = event.mouseMove.y;
	double boundleft = getPosition().x - width_ / 2;
	double boundright = getPosition().x + width_ / 2;
	double boundtop = getPosition().y  - height_ / 2;
	double boundbottom = getPosition().y + height_ / 2;

	if (event.type == sf::Event::MouseButtonPressed) {
		MouseStatus_ = true;
		PressedX_ = event.mouseButton.x;
		PressedY_ = event.mouseButton.y;
	}
	if (event.type == sf::Event::MouseButtonReleased)
		MouseStatus_ = false;
	
	if (MouseStatus_ && event.type == sf::Event::MouseMoved && //Зажата ЛКМ и мышь двигается
		IsWithinBoundaries(x, y, boundleft, boundright, boundtop, boundbottom) &&
		IsWithinBoundaries(PressedX_, PressedY_, boundleft, boundright, boundtop, boundbottom))
	{
		PressedX_ = x;
		PressedY_ = y;
		setPosition(x , y);
	}
}
