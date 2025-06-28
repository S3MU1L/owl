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

std::vector< Token > get_tokens( const std::string& filename );