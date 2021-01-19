/*************************
* Class Logarithm        *
* TNG033: Lab 2          *
**************************/


#ifndef LOGARITHM_H
#define LOGARITHM_H

#include <iostream>

#include "expression.h"

class Logarithm : public Expression
{
public:
	Logarithm();

	~Logarithm();

	Logarithm(const Expression& exp, const double const1, const double const2, const int b);

	Logarithm(const Logarithm& l);

	Logarithm* clone() const override;

	Logarithm& operator=(Logarithm l);

	double operator()(double d) const override;
	
private:
	double c1, c2;
	int base;
	Expression* e;
	void display(std::ostream& os) const override;
};

#endif
