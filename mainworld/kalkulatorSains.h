#pragma once
#define KALKULATORSAINS_H

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

		return 0;
	}
};
