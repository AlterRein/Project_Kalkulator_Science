#include <iostream>
#include <cstdlib>
#include <cmath>

//Class Father
class Operator {
protected:
	char op;
	double num1;
	double num2;
public:

	virtual double hitB() = 0;
	virtual double hitS() = 0;

	virtual ~Operator() {}
};

//First Child Class
class kalkulatorBiasa : public Operator {
public:
	double hitB() override {
		switch (op) {
		case '+': return num1 + num2;
			break;
		case '-': return num1 - num2;
			break;
		case '*': return num1 * num2;
			break;
		case '/':
			if (num2 == 0) {
				std::cout << "!! Num2 tidak boleh berisi"; return 0;
			}
			return num1 / num2;
			break;
		}
	}
};

//Second Child Class
class kalkulatorSains : public Operator {
	double hitS() override {
		if (op == 'p' || op == 'P') {
			return pow(num1, num2);
		}
		else if (op == 'a' || op == 'A') {
			return sqrt(num1);
		}
	}
};

int main() {
	Operator* call = nullptr;
	char cokal;

	do {
		system("cls");
		std::cout << "===============Kalkulator Ilmiah===============" << std::endl;
		std::cout << "           >> Berbasis OOP-MM-PR <<            " << std::endl;
		std::cout << "           [A] -Kalkulator Biasa-              " << std::endl;
		std::cout << "           [B] -Kalkulator Sains-              " << std::endl;
		std::cout << "           [C] -Close Kalkulator-              " << std::endl;
		std::cout << "===============================================" << std::endl;
		std::cout << "           Pilih : [A] || [B] || [C]           " << std::endl;

		std::cin >> cokal;
		if (cokal == 'a' || cokal == 'A') {
			char op;
			double num1, num2;
			std::cout << "Pilih Operator: [ + | - | * | / ]" << std::endl;
			std::cout << ">> "; std::cin >> op;
			if (op == '+' || op == '-' || op == '*' || op == '/') {
				std::cout << "Masukan num1: "; std::cin >> num1;
				std::cout << "Masukan num2: "; std::cin >> num2;
				if (!std::cin) {
					std::cout << "!! Num1 dan num2 harus berupa angka !!" << std::endl;
					std::cin.clear(); std::cin.ignore(1000, '\n');
				}
				else {
					std::cout << "#JUMLAH# = " << call->hitB() << std::endl;
				}
			}
			std::cout << "Tekan enter untuk melanjutkan..." << std::endl;
			std::cin.ignore();
			std::cin.get();
		}
		else if (cokal == 'b' || cokal == 'B') {
			char menuSains;
			double num1, num2;
			std::cout << "Peluh Menu Sains yang tersedia: " << std::endl;
			std::cout << "[1] Pangkat. \n[2] Akar kuadrat." << std::endl;
			std::cout << ">> "; std::cin >> menuSains;
			if (menuSains == '1') {
				std::cout << "Masukan Basis: "; std::cin >> num1;
				std::cout << "Masukan Eksponen: "; std::cin >> num2;

				std::cout << "#HASIL PANGKAT# = " << call->hitS() << std::endl;
				
			}
			else if (menuSains == '2') {
				std::cout << "Masukan angka yang di Akar: "; std::cin >> num1;

				std::cout << "#HASIL AKAR# = " << call->hitS() << std::endl;
			}
			std::cout << "Tekan enter untuk kembali..." << std::endl;
			std::cin.ignore(); std::cin.get();
		}
		else if (cokal == 'c' || cokal == 'C') {
			std::cout << "=-=-=-=-= Terimakasih Sudah Menggunakan KALKULKATOR saya =-=-=-=-=\n" << std::endl;
			break;
		}

		if (call != nullptr) {
			delete call;
			call = nullptr;
		}
	} while (cokal == 'c' || cokal == 'C');

	return 0;
}