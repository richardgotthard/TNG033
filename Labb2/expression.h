/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <iomanip>
#include <cmath>

const double EPSILON = 1.0e-5;


class Expression
{
public:

	virtual ~Expression() = default;

	bool isRoot(const double& d) const;

	virtual double operator()(double d) const = 0;

	virtual Expression* clone() const = 0;

	friend std::ostream& operator<<(std::ostream& os, const Expression& E);
	virtual Expression& operator=(const Expression&) = delete;

protected:

	Expression() = default;

	Expression(const Expression&) = default;

	virtual void display(std::ostream& os) const = 0;
	
};


#endif
