#include <iostream>
#include <stdexcept>
#include "calc.h"

int add(int a, int b) {
	return a + b;
};

int subtract(int a, int b) {
	return a - b;
};

int multiply(int a, int b) {
	return a * b;
};

double divide(int a, int b) {
	if (b == 0) { throw std::runtime_error("Делить не 0 нельзя!"); }
	return static_cast<double>(a) / b;
};

int factorial(int n) {
	if (n < 0) { throw std::runtime_error("Нельзя получить факториал отрицательного числа!"); }
	if (n == 0) { return 1; }
	if (n == 1) { return 1; }
	return n * factorial(n - 1);
};

double power(int base, int exponent) {
	if (exponent == 0) { return 1; }
	else if (exponent < 0) { return 1.0 / power(base, -exponent); }
	else { return base * power(base, exponent - 1); }
}