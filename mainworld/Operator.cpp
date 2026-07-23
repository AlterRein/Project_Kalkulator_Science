#include "Operator.h"

void Operator::setInput(char top, double tnum1, double tnum2) {
    op = top;
    num1 = tnum1;
    num2 = tnum2;
}

void Operator::setInputP(double basis, double eksponen) {
    op = 'p';
    num1 = basis;
    num2 = eksponen;
}

void Operator::setInputAk(double angka) {
    op = 'a';
    num1 = angka;
}
