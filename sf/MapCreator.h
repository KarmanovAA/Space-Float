#pragma once
#include <vector>
#include "MovSprite.h"


enum PlanetType { start, ordinary, finish };

struct Planet {
	double Radius;
	double Mass;
	PlanetType Pt;
};


class MapCreator
{
public:
	MapCreator();
	~MapCreator();
	void SetActive();
	void Draw(sf::RenderWindow& win);

	sf::Texture Background, SettingLine;
	sf::Sprite SL[5], Bg;
	sf::Text rad_, mass_;
	int winheight_ = 0;
	int winwidth_ = 0;
	PlanetType new_plan_type = start; ///
	double new_plan_radius = 0;    ///    may not be needed 
	double new_plan_mass = 0;      ///
	std::vector<Planet> Planets;
};

