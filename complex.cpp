#include "complex.hpp"

complex operator+(const complex &lhs, const complex &rhs){
	complex x = lhs;
	x += rhs;
	return x;
}

complex operator-(const complex &lhs, const complex &rhs){
	complex x = lhs;
	x -= rhs;
	return x;
}

complex operator*(const complex &lhs, const complex &rhs){
	complex x = lhs;
	x *= rhs;
	return x;
}

complex polar(const double &rho, const double &theta) {
	return complex(rho * cos(theta), rho * sin(theta));
}