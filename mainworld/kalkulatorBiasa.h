#pragma once
#define KALKULATOR_BIASA_H

#include "Operator.h"
#include <iostream>

//First Child Class
class kalkulatorBiasa : public Operator {
public:
	double hit() override {
		switch (op) {
		case '+': return num1 + num2;
		case '-': return num1 - num2;
		case '*': return num1 * num2;
		case '/':
			if (num2 == 0) {
				std::cout << "!! Num2 tidak boleh berisi"; return 0;
			}
			return num1 / num2;
		}
		return 0;
	}
};

