#pragma once
#include "Operator.h"
#include <iostream>

//Second Child Class
class kalkulatorSains : public Operator {
public:
	double hit() override {
		if (op == 'p' || op == 'P') {
			return pow(num1, num2);
		}
		else if (op == 'a' || op == 'A') {
			return sqrt(num1);
		}
		else if (op == 'l' || op == 'L') {
			return log(num1);
		}
		else if (op == 'e' || op == 'E') {
			return exp(num1);
		}
		else if (op == 's' || op == 'S') {
			return sin(num1);
		}
		else if (op == 'c' || op == 'C') {
			return cos(num1);
		}
		else if (op == 't' || op == 'T') {
			return tan(num1);
		}
		else {
			std::cout << "!! Operator Tidak Valid !!";
		}

		return 0;
	}
};
