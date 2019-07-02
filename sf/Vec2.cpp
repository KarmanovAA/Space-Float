#include <iostream>
#include <cmath>
#include <assert.h>
using std::cout;
using std::cin;


class Vec2
{
private:
	double X, Y;
public:
	Vec2(double a = 0.0, double b = 0.0) : X(a), Y(b) {}

	Vec2 operator + (Vec2 & a);
	Vec2 operator - (Vec2 & a);
	Vec2 operator / (Vec2 & a);
	Vec2 operator / (double a);
	Vec2 operator * (double a);
	Vec2 & operator += (const Vec2 & a);
	Vec2 & operator -= (const Vec2 & a);
	double getX();
	double getY();
	void setX(double _X);
	void setY(double _Y);
	void set(double a, double b);
	double abs();
	double abs2();
	void normalize();
	friend std::ostream & operator << (std::ostream &, const Vec2 &);
};

Vec2 Vec2::operator + (Vec2 & a)
{
	Vec2 tmp(0.0, 0.0);
	tmp.X = X + a.X;
	tmp.Y = Y + a.Y;
	return tmp;
}

Vec2 Vec2::operator - (Vec2 & a)
{
	Vec2 tmp(0.0, 0.0);
	tmp.X = X - a.X;
	tmp.Y = Y - a.Y;
	return tmp;
}

Vec2 Vec2::operator / (Vec2 & a)
{
	Vec2 tmp(0.0, 0.0);
	tmp.X = X / a.X;
	tmp.Y = Y / a.Y;
	return tmp;
}

Vec2 Vec2::operator / (double a)
{
	Vec2 tmp(0.0, 0.0);
	tmp.X = X / a;
	tmp.Y = Y / a;
	return tmp;
}

Vec2 Vec2::operator * (double a)
{
	Vec2 tmp(0.0, 0.0);
	tmp.X = X * a;
	tmp.Y = Y * a;
	return tmp;
}

Vec2 & Vec2::operator += (const Vec2 & a)
{
	X += a.X;
	Y += a.Y;
	return *this;
}

Vec2 & Vec2::operator -= (const Vec2 & a)
{
	X -= a.X;
	Y -= a.Y;
	return *this;
}

double Vec2::getX()
{
	return X;
}

double Vec2::getY()
{
	return Y;
}

void Vec2::setX(double _X)
{
	X = _X;
}

void Vec2::setY(double _Y)
{
	Y = _Y;
}

void Vec2::set(double a, double b)
{
	X = a;
	Y = b;
}

double Vec2::abs()
{
	return sqrt(X * X + Y * Y);
}

double Vec2::abs2()
{
	return (X * X + Y * Y);
}

void Vec2::normalize()
{
	double magnitude = sqrt(X * X + Y * Y);
	X /= magnitude;
	Y /= magnitude;
}

std::ostream & operator << (std::ostream & out, const Vec2 & a)
{
	out << a.X << " " << a.Y << " ";
	return  out;
}
