#include "VelocityBar.cpp"

#define G 6.67*0.0001

enum PlanetType { start, ordinary, finish };


class Object {
public:
	Vec2 r_vec_;
	long mass_ = 0;

	void SetMass(const long& m);
	void SetX(const double& wanted_x);
	void SetY(const double& wanted_y);
	void Set(const double& wanted_x, const double& wanted_y, const long& wanted_mass);
	Vec2 CalculateAccel(Object& rhs);
};


class SpaceShip : public Object {
	sf::Texture tex_;
	void OrientSprite();
public:
	Vec2 vel_ = 0;
	sf::Sprite spr_;

	SpaceShip();
	void Set(double w_x, double w_y);
	void SetVel(const double& wanted_x_vel, const double& wanted_y_vel);
	void ReCalculateVelocity(Vec2 force, double dt);
	void ReCalculateCoords(double dt);
	void Draw(sf::RenderWindow& win);
};


class Planet : public Object {
public:
	sf::Texture tex_;
	sf::Sprite spr_;
	PlanetType pt_;

	Planet() {}
	Planet(double mass, Vec2 pos, PlanetType pt);
	void PlanSet(double mass, Vec2 pos, PlanetType pt);
	void Draw(sf::RenderWindow&);
	void PlanetFromString(std::string& plan_info);
};

