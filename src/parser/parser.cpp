#include<iostream>
#include<string>
#include<vector>

class Parser{
	std::vector<Token> tokens;
	size_t pos = 0;
	
public:
	Parser(std::vector<Token> t) : tokens(std::move(t)) {}

	std::unique_ptr<Expr> parse() {

	}
};