/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"


//ADD implementation of the member functions for class Polynomial



Polynomial::Polynomial(int deg, const double v[]): degree(deg), coef(new double[degree + 1])
{
	for (int i = 0; i <= degree; i++) {
		coef[i] = v[i];
	}
};

Polynomial::Polynomial(double constant) : degree(0), coef(new double(constant))
{};

Polynomial::Polynomial(const Polynomial& b): degree(b.degree), coef(new double[b.degree + 1])
{
	for (int i = 0; i <= b.degree; i++) {
		coef[i] = b.coef[i];
	}
}

Polynomial::~Polynomial()
{
	delete[] coef;
	coef = nullptr;
}
;

void Polynomial::display(std::ostream& os) const {

	for (int i = 0; i < degree+1; i++) {
		if (coef[i] != 0) {
			os << std::setprecision(2) << std::fixed << coef[i];
			if (i > 0) {
				os << " * X^" << i;
			}
			if (i != degree) {
				os << " + ";
			}
		}
	}
}

Polynomial& Polynomial::operator=(const Polynomial& b)
{
	Polynomial copy{b};
	degree = b.degree;
	std::swap(coef, copy.coef);

	return *this;
}

Polynomial * Polynomial::clone() const
{
	return new Polynomial(*this);
}

double& Polynomial::operator[](const int e)
{
	return coef[e];	
}

double Polynomial::operator[](const int e) const
{
	return coef[e];
}

double Polynomial::operator()(double d) const
{
	double evaluated = 0;

	for (int i = 0; i <= degree; i++) {
		evaluated += coef[i] * pow(d, i);
	}

	return evaluated;
}


Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs)
{
	if (lhs.degree >= rhs.degree) {
		Polynomial temp(lhs);

		for (int i = 0; i <= rhs.degree; i++) {
			temp.coef[i] += rhs.coef[i];
		}

		return temp;
	}

	Polynomial temp(rhs);

	for (int i = 0; i <= lhs.degree; i++) {
		temp.coef[i] += lhs.coef[i];
	}

	return temp;
}
