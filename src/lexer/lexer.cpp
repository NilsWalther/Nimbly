#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<cctype>

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
    ASSIGN,
    END
};

struct Token {
    TokenType type;
    std::string value;
};


std::string read_source_file(const std::string& filename){
    std::fstream file(filename, std::ios::in);

    //Fehler beim öffnen der Datei
    if(!file.is_open()){
        std::cerr << "Fehler: Datei konnte nicht geöffnet werden.\n";
        return "";
    }
    
    //Datei Inhalt in Buffer zwischenspeichern und als String zurückgeben
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    
    return buffer.str();

}

std::vector<Token> translate_to_tokens(std::string& code){
    std::vector<Token> tokens;
    size_t i = 0;//index

    while (i < code.size()) {
        char c = code[i];
        
        //Space -> überspringen
        if(std::isspace(static_cast<unsigned char>(c))){
            i++;
            continue;
        }
        //Kommentar mit '//' -> ganze Zeile überspringen
        if(c == '/' && i + 1 < code.size() && code[i + 1] == '/'){
            i += 2;
            while(i < code.size() && code[i] != '\n'){
                i++;
            }
            continue;
        }
        //Zahl -> zu Tokens hinzufügen
        if(std::isdigit(static_cast<unsigned char>(c))){
            std::string number;
            while(i < code.size() && std::isdigit(static_cast<unsigned char>(code[i]))){
                number += code[i];
                i++;
            }
            tokens.push_back({TokenType::NUMBER, number});
            continue;
        }
        //Identifier oder Name
        //Wenn c Buchstabe ist -> bis zum ende solange c Buchstabe oder Zahl ist
        if(std::isalpha(static_cast<unsigned char>(c))){
            std::string ident;
            while(i < code.size() &&
            (std::isalnum(static_cast<unsigned char>(code[i])))){
                ident += code[i];
                i++;
            }
            tokens.push_back({TokenType::IDENTIFIER, ident});
            continue;
        }
        if (c == ';') {
            tokens.push_back({TokenType::SEMICOLON, ";"});
            i++;
            continue;
        }
        //Einzelzeichen
        switch (c) {
            case '=':
                tokens.push_back({TokenType::ASSIGN, "="});
                break;
            case '+':
                tokens.push_back({TokenType::PLUS, "+"});
                break;
            case '-':
                tokens.push_back({TokenType::MINUS, "-"});
                break;
            case '*':
                tokens.push_back({TokenType::MUL, "*"});
                break;
            case '/':
                tokens.push_back({TokenType::DIV, "/"});
                break;
            case '(':
                tokens.push_back({TokenType::LPAREN, "("});
                break;
            case ')':
                tokens.push_back({TokenType::RPAREN, ")"});
                break;
            default:
                std::cerr << "Unbekanntes Zeichen: " << c << "\n";
                break;
        }

        i++;
    }
    tokens.push_back({TokenType::END, ""});
    return tokens;
}


std::string token_type_to_string(TokenType type) {
    switch (type) {
        case TokenType::NUMBER:     return "NUMBER";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::PLUS:       return "PLUS";
        case TokenType::MINUS:      return "MINUS";
        case TokenType::MUL:        return "MUL";
        case TokenType::DIV:        return "DIV";
        case TokenType::LPAREN:     return "LPAREN";
        case TokenType::RPAREN:     return "RPAREN";
        case TokenType::SEMICOLON:  return "SEMICOLON";
        case TokenType::ASSIGN:     return "ASSIGN";
        case TokenType::END:        return "END";
        default:                    return "UNKNOWN";
    }
}
