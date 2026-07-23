#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include "Operator.h"
#include "kalkulatorBiasa.h"
#include "kalkulatorSains.h"

int main() {
	std::unique_ptr<Operator> call;
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

		std::cout << ">> "; std::cin >> cokal;
		if (cokal == 'a' || cokal == 'A') {
			call = std::make_unique<kalkulatorBiasa>();
			char op;
			double num1, num2;
			std::cout << "Pilih Operator: [ + | - | * | / ]" << std::endl;
			std::cout << ">> "; std::cin >> op;
			if (op == '+' || op == '-' || op == '*' || op == '/') {
				std::cout << "Masukan num1: "; std::cin >> num1;
				std::cout << "Masukan num2: "; std::cin >> num2;
				call->setInput(op, num1, num2);
				if (!std::cin) {
					std::cout << "!! Num1 dan num2 harus berupa angka !!" << std::endl;
					std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				std::cout << "#JUMLAH# = " << call->hit() << std::endl;
			}
			else {
				std::cout << "!! Operator Tidak Valid !!";
			}

			std::cout << "Tekan enter untuk melanjutkan..." << std::endl;
			std::cin.ignore();
			std::cin.get();

			continue;
		}
		else if (cokal == 'b' || cokal == 'B') {
			call = std::make_unique<kalkulatorSains>();
			char menuSains;
			double num1, num2;
			std::cout << "Peluh Menu Sains yang tersedia: " << std::endl;
			std::cout << "[1] Pangkat. \n[2] Akar kuadrat." << std::endl;
			std::cout << ">> "; std::cin >> menuSains;
			if (menuSains == '1') {
				std::cout << "Masukan Basis: "; std::cin >> num1;
				std::cout << "Masukan Eksponen: "; std::cin >> num2;

				call->setInputP(num1, num2);
				std::cout << "#HASIL PANGKAT# = " << call->hit() << std::endl;
			}
			else if (menuSains == '2') {
				std::cout << "Masukan angka yang di Akar: "; std::cin >> num1;

				call->setInputAk(num1);
				std::cout << "#HASIL AKAR# = " << call->hit() << std::endl;
			}
			std::cout << "Tekan enter untuk kembali..." << std::endl;
			std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cin.get();

			continue;
		}
		else if (cokal == 'c' || cokal == 'C') {
			std::cout << "=-=-=-=-= Terimakasih Sudah Menggunakan KALKULKATOR saya =-=-=-=-=\n" << std::endl;
			break;
		}

		// unique_ptr will automatically release any held object
	} while (cokal != 'c' && cokal != 'C');

	return 0;
}