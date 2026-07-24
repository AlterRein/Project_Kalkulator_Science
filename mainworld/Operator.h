#pragma once

//Class Father
class Operator {
protected:
	char op = ' ';
	double num1 = 0.0;
	double num2 = 0.0;
public:

	void setInput(char top, double tnum1, double tnum2);

	void setInputP(double basis, double eksponen);

	void setInputAk(double angka);

	void setInputLog(double angka);

	void setInputExp(double angka);

	void setInputSin(double angka);

	void setInputCos(double angka);

	void setInputTan(double angka);

	virtual double hit() = 0;

	virtual ~Operator() {}
};