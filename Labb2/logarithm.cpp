/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"

//ADD implementation of the member functions for class Logarithm

Logarithm::Logarithm()
{
	double v[2] = { 0, 1 };
	base = 2;
	c1 = 0;
	c2 = 1;
	e = new Polynomial{ 1, v };
}

Logarithm::~Logarithm()
{
	delete e;
	e = nullptr;
	base = 0;
	c1 = 0;
	c2 = 0;
}

Logarithm::Logarithm(const Expression & exp, double const1, double const2, int b)
{
	c1 = const1;
	c2 = const2;
	base = b;
	e = exp.clone();
}

Logarithm::Logarithm(const Logarithm & l)
{
	c1 = l.c1;
	c2 = l.c2;
	base = l.base;
	e = l.e->clone();

}

double Logarithm::operator()(const double d) const
{
	double evaluated = c1 + c2 * (log(e->operator()(d)) / log(base));

	return evaluated;
}

Logarithm * Logarithm::clone() const
{
	return (new Logarithm(*this));
}

Logarithm & Logarithm::operator=(Logarithm l)
{
	std::swap(c1, l.c1);
	std::swap(c2, l.c2);
	std::swap(base, l.base);
	std::swap(e, l.e);

	return *this;

}

void Logarithm::display(std::ostream & os) const
{

	std::cout << c1 << " + " << c2 << "*" << "Log_" << base
	<< "( " << *e << ")";


}