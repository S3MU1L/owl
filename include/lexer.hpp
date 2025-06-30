#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

#include "token.hpp"

struct LexerException : public std::exception
{
    const char* what() const noexcept override
    {
        return "Lexer error occurred";
    }
};

struct Lexer
{
    int start = 0;
    int current = 0;
    int line = 1;
    std::vector< Token > tokens{};
    std::ifstream istream;

    Lexer( const std::string& filename ) : istream(filename) {
        if (!istream.is_open()) {
            throw LexerException();
        }
    }

    std::vector< Token > scan_tokens();

    Token scan_token();
    
    char advance();

    char peek();

    bool is_finished();

    void skip_whitespace();
};
