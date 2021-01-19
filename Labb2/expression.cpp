/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"

//ADD implementation of the member functions for class Expression

bool Expression::isRoot(const double& d) const //tar in funktionen med x inuti. om x i funktionen ger noll är det en rot
{	
	return(fabs((*this)(d)) < EPSILON);
}

std::ostream& operator<<(std::ostream& os, const Expression& E)
{
	E.display(os);
	return os;
}
//
//Expression Expression::clone()
//{
//	return Expression();
//}
