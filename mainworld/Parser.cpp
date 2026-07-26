#include "Parser.h"
#include <stack>
#include <stdexcept>
#include <map>

// Fungsi pembantu untuk mengecek kekuatan operator
int getPrecedence(const std::string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;
    return 0;
}

// Pangkat (^) sifatnya Right-Associative
bool isRightAssociative(const std::string& op) {
    return op == "^";
}

std::vector<Token> shuntingYard(const std::vector<Token>& tokens) {
    std::vector<Token> outputQueue;
    std::stack<Token> opStack;

    for (const auto& token : tokens) {
        // 1. Jika token berupa Angka -> Langsung masuk ke Output
        if (token.type == TokenType::NUMBER) {
            outputQueue.push_back(token);
        }
        // 2. Jika token berupa Fungsi (sin, cos, log, dll) -> Masuk ke Stack Operator
        else if (token.type == TokenType::FUNCTION) {
            opStack.push(token);
        }
        // 3. Jika token berupa Operator (+, -, *, /, ^)
        else if (token.type == TokenType::OPERATOR) {
            while (!opStack.empty() && opStack.top().type != TokenType::LEFT_PAREN) {
                Token top = opStack.top();

                int prec1 = getPrecedence(token.value);
                int prec2 = getPrecedence(top.value);

                // Pindahkan operator dari Stack ke Output jika operator di Stack lebih kuat / setara
                if ((top.type == TokenType::OPERATOR &&
                    ((!isRightAssociative(token.value) && prec1 <= prec2) ||
                        (isRightAssociative(token.value) && prec1 < prec2))) ||
                    top.type == TokenType::FUNCTION) {
                    outputQueue.push_back(top);
                    opStack.pop();
                }
                else {
                    break;
                }
            }
            opStack.push(token);
        }
        // 4. Jika Kurung Buka '(' -> Masuk ke Stack
        else if (token.type == TokenType::LEFT_PAREN) {
            opStack.push(token);
        }
        // 5. Jika Kurung Tutup ')' -> Kuras Stack ke Output sampai ketemu Kurung Buka
        else if (token.type == TokenType::RIGHT_PAREN) {
            bool foundLeftParen = false;
            while (!opStack.empty()) {
                if (opStack.top().type == TokenType::LEFT_PAREN) {
                    foundLeftParen = true;
                    opStack.pop(); // Buang '(' dari stack
                    break;
                }
                outputQueue.push_back(opStack.top());
                opStack.pop();
            }

            if (!foundLeftParen) {
                throw std::invalid_argument("Kurung tidak seimbang! Ada ')' tanpa '(' yang cocok.");
            }

            // Jika di atas stack ada Fungsi, pindahkan juga ke Output
            if (!opStack.empty() && opStack.top().type == TokenType::FUNCTION) {
                outputQueue.push_back(opStack.top());
                opStack.pop();
            }
        }
    }

    // Pindahkan sisa operator di Stack ke Output
    while (!opStack.empty()) {
        if (opStack.top().type == TokenType::LEFT_PAREN || opStack.top().type == TokenType::RIGHT_PAREN) {
            throw std::invalid_argument("Kurung tidak seimbang dalam ekspresi!");
        }
        outputQueue.push_back(opStack.top());
        opStack.pop();
    }

    return outputQueue;
}