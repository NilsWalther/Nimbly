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
    size_t i = 0;

    while (i < code.size()) {
        char c = code[i];
        //...
    }
}

int main(int argc, char* argv[]){
    std::string code = read_source_file(argv[1]);
    std::cout << code << std::endl;
    return 0;
}
