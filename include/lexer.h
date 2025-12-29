#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

// Token-Typen
enum class TokenType {
    NUMBER,
    IDENTIFIER,
    PLUS,
    MINUS,
    MUL,
    DIV,
    LPAREN,
    RPAREN,
    SEMICOLON,
    END
};

// Token-Struktur
struct Token {
    TokenType type;
    std::string value;
};

// Funktionsdeklarationen
std::string read_source_file(const std::string& filename);
std::vector<Token> translate_to_tokens(std::string& code);
std::string token_type_to_string(TokenType type);
#endif // LEXER_H
