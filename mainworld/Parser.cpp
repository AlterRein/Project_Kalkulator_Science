#include "Parser.h"
#include <stdexcept>

// Fungsi pembantu untuk mengecek apakah karakter adalah operator
bool isOperatorChar(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

std::vector<Token> tokenize(const std::string& expression) {
    std::vector<Token> tokens;
    size_t i = 0;
    size_t length = expression.length();

    while (i < length) {
        char currentChar = expression[i];

        // 1. Abaikan karakter spasi
        if (std::isspace(currentChar)) {
            i++;
            continue;
        }

        // 2. Jika ditemui Angka atau Titik Desimal (Mendukung Floating Point)
        if (std::isdigit(currentChar) || currentChar == '.') {
            std::string numStr = "";
            while (i < length && (std::isdigit(expression[i]) || expression[i] == '.')) {
                numStr += expression[i];
                i++;
            }
            tokens.push_back({ TokenType::NUMBER, numStr });
        }
        // 3. Jika ditemui Karakter Teks (Fungsi Sains seperti sin, cos, tan, log, sqrt)
        else if (std::isalpha(currentChar)) {
            std::string funcStr = "";
            while (i < length && std::isalpha(expression[i])) {
                funcStr += expression[i];
                i++;
            }
            tokens.push_back({ TokenType::FUNCTION, funcStr });
        }
        // 4. Jika ditemui Operator Matematika
        else if (isOperatorChar(currentChar)) {
            tokens.push_back({ TokenType::OPERATOR, std::string(1, currentChar) });
            i++;
        }
        // 5. Kurung Buka
        else if (currentChar == '(') {
            tokens.push_back({ TokenType::LEFT_PAREN, "(" });
            i++;
        }
        // 6. Kurung Tutup
        else if (currentChar == ')') {
            tokens.push_back({ TokenType::RIGHT_PAREN, ")" });
            i++;
        }
        // Jika ada karakter asing/tidak dikenali
        else {
            throw std::invalid_argument("Karakter tidak valid ditemukan dalam ekspresi: " + std::string(1, currentChar));
        }
    }

    return tokens;
}