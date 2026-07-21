#include <iostream>
#include <cstdlib>
#include <cmath>

class Operator {
protected:
	char pangkat;
	char akar;
	char op;
	double num1;
	double num2;
	double jumlah;
public:
	char c;

	void setInput(char top, double tnum1, double tnum2) {
		op = top;
		num1 = tnum1;
		num2 = tnum2;
	}

	virtual double hit() = 0;

	virtual ~Operator() {}
};

class kalkulatorSains : public Operator {
public:
	double hit() override {
		if (op == 'p' || op == 'P') {
			return pow(num1, num2);
		}
		else if (op == 'a' || op == 'A') {
			return sqrt(num1);
		}
	}
};

class kalkulatorBiasa : public Operator {
public:
	double hit() override {
		switch (op) {
		case '+':
			jumlah = num1 + num2;
			break;
		case '-':
			jumlah = num1 - num2;
			break;
		case '*':
			jumlah = num1 * num2;
			break;
		case '/':
			if (num2 == 0) {
				std::cout << "!!num2 tidak boleh bernilai ";
				jumlah = 0;
			}
			else {
				jumlah = num1 / num2;
			}
			break;
		}
		return jumlah;
	}
};

int main() {
    Operator* call = nullptr;
    char pilihkalkulator;

    do {
        system("cls");
        std::cout << "=============KALKULATOR=============" << std::endl;
        std::cout << "       >>Write in C++ (OOP)<<       " << std::endl;
        std::cout << "      [A] Kalkulator Biasa          " << std::endl;
        std::cout << "      [B] Kalkulator Sains          " << std::endl;
        std::cout << "      [C] Close Kalkuator           " << std::endl;
        std::cout << "                                    " << std::endl;
        std::cout << ">> Pilih [A] || [B] || [C] \n";
        std::cout << ">> "; std::cin >> pilihkalkulator;

        if (pilihkalkulator == 'c' || pilihkalkulator == 'C') {
            std::cout << "--Terimakasih sudah menggunakan KALKULATOR saya--\n";
            break;
        }

        if (pilihkalkulator == 'a' || pilihkalkulator == 'A') {
            call = new kalkulatorBiasa();

            char op;
            double num1, num2;
            std::cout << "Pilih Operator (+, -, *, /): "; std::cin >> op;

            if (op == '+' || op == '-' || op == '*' || op == '/') {
                std::cout << "Masukan num1: "; std::cin >> num1;
                std::cout << "Masukan num2: "; std::cin >> num2;
                call->setInput(op, num1, num2);
                std::cout << "#JUMLAH#: " << call->hit() << std::endl;
            }
            else {
                std::cout << "!! Operator salah !!" << std::endl;
            }

            std::cout << "Tekan Enter untuk kembali...";
            std::cin.ignore(); std::cin.get();
        }
        else if (pilihkalkulator == 'b' || pilihkalkulator == 'B') {
            call = new kalkulatorSains();

            char menuSains;
            std::cout << "\n[1] Pangkat \n[2] Akar kuadrat \nPilih Menu: ";
            std::cin >> menuSains;

            if (menuSains == '1') {
                double basis, eksponen;
                std::cout << "Masukan basis: "; std::cin >> basis;
                std::cout << "Masukan eksponen: "; std::cin >> eksponen;
                call->setInput('p', basis, eksponen);
                std::cout << "#JUMLAH#: " << call->hit() << std::endl;
            }
            else if (menuSains == '2') {
                double angka;
                std::cout << "Angka yang diakar: "; std::cin >> angka;
                call->setInput('q', angka, 0);
                std::cout << "#JUMLAH#: " << call->hit() << std::endl;
            }

            std::cout << "Tekan Enter untuk kembali...";
            std::cin.ignore(); std::cin.get();
        }
        if (call != nullptr) {
            delete call;
            call = nullptr;
        }

    } while (pilihkalkulator != 'c' && pilihkalkulator != 'C');

    return 0;
}