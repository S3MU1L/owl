#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

#include "../include/util.hpp"
#include "../include/lexer.hpp"
  
std::vector< Token > Lexer::scan_tokens()
{
    while ( !is_finished() )
    {
        start = current;
        Token token = scan_token();
        if ( token.type != TokenType::COMMENT ) 
            tokens.push_back(token);
    }
    return tokens;
}

Token Lexer::scan_token()
{
    skip_whitespace();
    char c = advance();
    if ( is_finished() )
        return { TokenType::EOF_TOKEN, "", line };

    if ( c == '(' ) return { TokenType::LEFT_PAREN, "(", line };
    if ( c == ')' ) return { TokenType::RIGHT_PAREN, ")", line };
    if ( c == '{' ) return { TokenType::LEFT_BRACE, "{", line };
    if ( c == '}' ) return { TokenType::RIGHT_BRACE, "}", line };
    if ( c == '[' ) return { TokenType::LEFT_BRACKET, "[", line };
    if ( c == ']' ) return { TokenType::RIGHT_BRACKET, "]", line };
    if ( c == ',' ) return { TokenType::COMMA, ",", line };
    if ( c == '.' ) return { TokenType::DOT, ".", line };
    if ( c == ';' ) return { TokenType::SEMICOLON, ";", line };
    if ( c == ':' ) return { TokenType::COLON, ":", line };
    if ( c == '-' ) return { TokenType::MINUS, "-", line };
    if ( c == '+' ) return { TokenType::PLUS, "+", line };
    if ( c == '/' ) return { TokenType::SLASH, "/", line };
    if ( c == '*' ) return { TokenType::STAR, "*", line };
    if ( c == '#' ) return { TokenType::COMMENT, "#", line }; 
    if ( c == '%' ) return { TokenType::PERCENT, "%", line };
    if ( c == '!' ) return { advance() == '=' ? TokenType::BANG_EQUAL : TokenType::BANG, "!", line };
    if ( c == '=' ) return { advance() == '=' ? TokenType::EQUAL_EQUAL : TokenType::EQUAL, "=", line };
    if ( c == '>' ) return { advance() == '=' ? TokenType::GREATER_EQUAL : TokenType::GREATER, ">", line };
    if ( c == '<' ) return { advance() == '=' ? TokenType::LESS_EQUAL : TokenType::LESS, "<", line };
    if ( c == '&' ) return { advance() == '&' ? TokenType::AND : TokenType::BANG, "&", line };
    if ( c == '|' ) return { advance() == '|' ? TokenType::OR : TokenType::BANG, "|", line };
    if ( std::isdigit( c ) )
    {
        std::string number;
        do
        {
            number += c;
            c = advance();
        } while ( std::isdigit( c ) );

        istream.putback( c ); 
        return { TokenType::NUMBER, number, line };
    }

    if ( std::isalpha( c ) || c == '_' )
    {
        std::string identifier;
        do
        {
            identifier += c;
            c = advance();
        } while ( std::isalnum( c ) || c == '_' );
        
        istream.putback( c ); 
        if ( identifier == "class" ) return { TokenType::CLASS, identifier, line };
        if ( identifier == "var" ) return { TokenType::VAR, identifier, line };
        if ( identifier == "if" ) return { TokenType::IF, identifier, line };
        if ( identifier == "else" ) return { TokenType::ELSE, identifier, line };
        if ( identifier == "while" ) return { TokenType::WHILE, identifier, line };
        if ( identifier == "for" ) return { TokenType::FOR, identifier, line };
        if ( identifier == "new" ) return { TokenType::NEW, identifier, line };
        if ( identifier == "init" ) return { TokenType::INIT, identifier, line };
        if ( identifier == "this" ) return { TokenType::THIS, identifier, line };
        if ( identifier == "true" ) return { TokenType::TRUE, identifier, line };
        if ( identifier == "false" ) return { TokenType::FALSE, identifier, line };
        if ( identifier == "nil" ) return { TokenType::NIL, identifier, line };
        if ( identifier == "return" ) return { TokenType::RETURN, identifier, line };
        if ( identifier == "break" ) return { TokenType::BREAK, identifier, line };
        if ( identifier == "continue" ) return { TokenType::CONTINUE, identifier, line };
        if ( identifier == "print" ) return { TokenType::PRINT, identifier, line };
        if ( identifier == "fun" ) return { TokenType::FUN, identifier, line };
        if ( identifier == "super" ) return { TokenType::SUPER, identifier, line };

        if ( identifier == "int" ) return { TokenType::INT, identifier, line };
        if ( identifier == "string" ) return { TokenType::STRING_TYPE, identifier, line };
        if ( identifier == "bool" ) return { TokenType::BOOL, identifier, line };
        if ( identifier == "float" ) return { TokenType::FLOAT, identifier, line };
        if ( identifier == "double" ) return { TokenType::DOUBLE, identifier, line };
        if ( identifier == "void" ) return { TokenType::VOID, identifier, line };

        return { TokenType::IDENTIFIER, identifier, line };
    }

    if ( c == '"' )
    {
        std::string string_literal;
        while ( !is_finished() && ( c = advance() ) != '"' )
        {
            if ( c == '\n' )
            {
                std::cerr << "Unterminated string at line: " << line << '\n';
                return { TokenType::EOF_TOKEN, "", line };
            }
            string_literal += c;
        }

        if ( is_finished() )
        {
            std::cerr << "Unterminated string at line: " << line << '\n';
            return { TokenType::EOF_TOKEN, "", line };
        }

        return { TokenType::STRING, string_literal, line };
    }

    std::cerr << "Unexpected character: '" << c << "' at line: " << line << ", at column: " << ( current - start ) << '\n';
    return { TokenType::EOF_TOKEN, "", line };
}

char Lexer::advance()
{
    char c = istream.get();
    if ( c == '\n' ) 
        ++line;
    
    ++current;
    return c;
}

char Lexer::peek()
{
    if ( is_finished() )
        return '\0'; 
    return istream.peek();
}

bool Lexer::is_finished()
{
    return istream.eof() || istream.peek() == EOF;
}

void Lexer::skip_whitespace()
{
    char c = peek();
    while ( !is_finished() && std::isspace( c ) )
    {
        if ( c == '\n' ) 
            ++line;
        advance();
        c = peek();
    }
}
