#include<iostream>
#include<string>
#include<vector>
#include"lexer.h"
#define FILE_EXTENSION ".nils"

#ifndef _WIN32
    #include<unistd.h>
#endif

int main(int argc, char* argv[]){
    if(argc < 2){
        std::cerr << "Bitte Dateinamen angeben!\n";
        return 1;
    }

    std::string code = read_source_file(argv[1]);
    auto tokens = translate_to_tokens(code);

    for(const auto& token : tokens){
        std::cout << "<"
                  << token_type_to_string(token.type)
                  << ", \"" << token.value << "\">"
                  << std::endl;
    }

    return 0;
}