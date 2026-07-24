#pragma once
#include <vector>
#include <string>

enum class TokenType {
	NUMBER,
	OPERATOR,
	FUNCTION,
	LEFT_PAREN,
	RIGHT_PAREN
};

struct Token {
	TokenType type;
	std::string value;
};

//Fungsi untuk Ekspresi Tokenizer
std::vector<Token> tokenize(const std::string& expression);