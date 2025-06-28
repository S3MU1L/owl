#include "../include/util.hpp"
#include "../include/token.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bool check_owl_filename( const std::string& filename )
{
    std::string::size_type n = filename.find(".");
    if ( std::string::npos == n )
    {
        std::cout << "File does not contain a dot\n";
        return false;
    }

    if ( filename.substr( n ) != ".ow" )
    {
        std::cout<< "File suffix is not .ow\n";
        return false;
    }

    return true;
}

std::string to_string( Token token )
{
    switch ( token.type )
    {
        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::LEFT_BRACE: return "LEFT_BRACE";
        case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
        case TokenType::COMMA: return "COMMA";
        case TokenType::DOT: return "DOT";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::MINUS: return "MINUS";
        case TokenType::PLUS: return "PLUS";
        case TokenType::SLASH: return "SLASH";
        case TokenType::STAR: return "STAR";
        case TokenType::PERCENT: return "PERCENT";
        case TokenType::BANG: return "BANG";
        case TokenType::BANG_EQUAL: return "BANG_EQUAL";
        case TokenType::EQUAL: return "EQUAL";
        case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
        case TokenType::GREATER: return "GREATER";
        case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
        case TokenType::LESS: return "LESS";
        case TokenType::LESS_EQUAL: return "LESS_EQUAL";
        case TokenType::AND: return "AND";
        case TokenType::OR: return "OR";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::STRING: return "STRING";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::CLASS: return "CLASS"; 
        case TokenType::VAR: return "VAR";
        case TokenType::IF: return "IF";
        case TokenType::ELSE: return "ELSE";
        case TokenType::WHILE: return "WHILE";
        case TokenType::FOR: return "FOR";
        case TokenType::NEW: return "NEW";
        case TokenType::INIT: return "INIT";
        case TokenType::THIS: return "THIS";
        case TokenType::TRUE: return "TRUE";
        case TokenType::FALSE: return "FALSE";
        case TokenType::NIL: return "NIL";
        case TokenType::RETURN: return "RETURN";
        case TokenType::BREAK: return "BREAK";
        case TokenType::CONTINUE: return "CONTINUE";
        case TokenType::PRINT: return "PRINT";
        case TokenType::FUN: return "FUN";
        case TokenType::SUPER: return "SUPER";
        case TokenType::EOF_TOKEN: return "EOF";
        default: return "UNRECOGNISED_TOKEN";
    }
}

void report( int line, const std::string& where, const std::string msg )
{
    std::cout << "[line " << line << "] Error " << where << ": " << msg << '\n';
}

void error( int line, const std::string& msg )
{
    report( line, "", msg );
}
