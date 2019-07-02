#include "GameObject.h"
#include <fstream>

void Object::SetMass(const long& m) {
	assert(m >= 0);
	mass_ = m;
}

void Object::SetX(const double& wanted_x) {
	//assert(wanted_x >= 0);
	r_vec_.setX(wanted_x);
}

void Object::SetY(const double& wanted_y) {
	//assert(wanted_y <= 0);
	r_vec_.setY(wanted_y);
}

void Object::Set(const double& wanted_x, const double& wanted_y, const long& wanted_mass) {
	this->SetX(wanted_x);
	this->SetY(wanted_y);
	this->SetMass(wanted_mass);
}

Vec2 Object::CalculateAccel(Object& rhs) {
	Vec2 accel = rhs.r_vec_ - r_vec_;
	double sq_dist = accel.abs2();
	accel.normalize();
	if(sq_dist != 0)
		accel = accel * G  * rhs.mass_ / sq_dist;
	return accel;
}


SpaceShip::SpaceShip() {
	if (!tex_.loadFromFile("SpaceShip.png"))
		std::cerr << "Cannot load texture" << std::endl;
	spr_.setTexture(tex_);
	spr_.setTextureRect(sf::IntRect(0, 0, 240, 146));
	spr_.setOrigin(120, 73);
	spr_.setScale(0.2, 0.2);
}

void SpaceShip::Set(double w_x, double w_y) {
	this->Object::Set(w_x, w_y, 1);
	spr_.setPosition(w_x, w_y);
}

void SpaceShip::SetVel(const double& wanted_x_vel, const double& wanted_y_vel) {
	vel_.set(wanted_x_vel, wanted_y_vel);
}

void SpaceShip::ReCalculateVelocity(Vec2 accel, double dt) {
	vel_ += accel * dt;// нужно вектором
//	std::cout << accel.abs() << std::endl;
}

void SpaceShip::ReCalculateCoords(double dt) {
	r_vec_ += vel_ * dt;
}

void SpaceShip::OrientSprite() {
	if (vel_.getX() > 0)
		spr_.setRotation(atan(vel_.getY() / vel_.getX()) * 180 / 3.14159);
	else
		spr_.setRotation(atan(vel_.getY() / vel_.getX()) * 180 / 3.14159 + 180);
}

void SpaceShip::Draw(sf::RenderWindow& win) {
	this->OrientSprite();
	win.draw(spr_);
}


Planet::Planet(double mass, Vec2 pos, PlanetType plt) {
	if (!tex_.loadFromFile("Planets1.png"))
		std::cerr << "Cannot load texture file";
	pt_ = plt;
	spr_.setTexture(tex_);
	if (pt_ == start) {
		spr_.setTextureRect(sf::IntRect(0,0,120,122));
		spr_.setOrigin(60, 61);
		spr_.setPosition(pos.getX(), pos.getY());
		Set(pos.getX(), pos.getY(), mass);
	}
	if (pt_ == ordinary) {
		spr_.setTextureRect(sf::IntRect(120, 0, 120, 122));
		spr_.setOrigin(60, 61);
		spr_.setPosition(pos.getX(), pos.getY());
		Set(pos.getX(), pos.getY(), mass);
	}
	if (pt_ == finish) {
		spr_.setTextureRect(sf::IntRect(240, 0, 120, 122));
		spr_.setOrigin(60, 61);
		spr_.setPosition(pos.getX(), pos.getY());
		Set(pos.getX(), pos.getY(), mass);
	}
}

void Planet::PlanSet(double mass, Vec2 pos, PlanetType plt) {
	if (!tex_.loadFromFile("Planets.png"))
		std::cerr << "Cannot load texture file";
	pt_ = plt;
	spr_.setTexture(tex_);
	if (pt_ == start) {
		spr_.setTextureRect(sf::IntRect(0, 0, 120, 122));
		spr_.setOrigin(60, 61);
		spr_.setPosition(pos.getX(), pos.getY());
		Set(pos.getX(), pos.getY(), mass);
	}
	if (pt_ == ordinary) {
		spr_.setTextureRect(sf::IntRect(120, 0, 120, 122));
		spr_.setOrigin(60, 61);
		spr_.setPosition(pos.getX(), pos.getY());
		Set(pos.getX(), pos.getY(), mass);
	}
	if (pt_ == finish) {
		spr_.setTextureRect(sf::IntRect(240, 0, 120, 122));
		spr_.setOrigin(60, 61);
		spr_.setPosition(pos.getX(), pos.getY());
		Set(pos.getX(), pos.getY(), mass);
	}
}


void Planet::PlanetFromString(std::string& plan_info) {
	int cur_pos = 0;
	std::string cur_str = "";
	double mass;
	Vec2 pos;
	PlanetType pt;
	for (const char& i : plan_info) 
	{
		if (i != ' ') 
		{
			cur_str += i;
		}
		else
		{
			if (cur_pos == 0) {
				mass = std::stod(cur_str);
			} else
			if (cur_pos == 1) {
				pos.setX(std::stod(cur_str));
			} else
			if (cur_pos == 2) {
				pos.setY(std::stod(cur_str));
			} else 
			if (cur_pos == 3) {
				switch (static_cast<int>(std::stod(cur_str)))
				{
				case 0:
					pt = start;
					break;
				case 1:
					pt = ordinary;
					break;
				case 2:
					pt = finish;
					break;
				}
			}
			cur_str = "";
			cur_pos++;
		}
	}
	this->PlanSet(mass, pos, pt);
}


void LoadPlanets(std::vector<Planet>& plts, std::string filepath) {
	std::string plan_info;
	std::ifstream input(filepath);
	int i = 0;
	plts.resize(100);
	if (input)
		while (getline(input, plan_info)) {
			plts[i].PlanetFromString(plan_info);
			i++;

		}
}

void Planet::Draw(sf::RenderWindow& rw) {
	rw.draw(spr_);
}



