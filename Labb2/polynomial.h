/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

#include "expression.h"


class Polynomial : public Expression
{

public:

	//Polynomial() = default;

	Polynomial(int degree, const double v[]);

	Polynomial(double constant);

	Polynomial(const Polynomial& b);

	~Polynomial();

	Polynomial& operator=(const Polynomial& b);
	
	double operator()(double d) const override;

	//Polynomial operator+(const Polynomial& b) const;

	//Polynomial operator+(double d);

	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs); 

	Polynomial* clone() const override;

	double& operator[](const int e);

	double operator[](const int e) const;

protected:

	int degree;
	double* coef;

private:
	void display(std::ostream& os) const override;
};



#endif
