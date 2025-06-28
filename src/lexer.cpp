#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

#include "../include/util.hpp"
#include "../include/lexer.hpp"

std::vector< Token > get_tokens( const std::string& filename )
{
    std::ifstream istrm{ filename };    
    if ( !istrm.is_open() )
        throw LexerException();

    std::vector< Token > tokens;
    std::string line;
    int line_number = 1;
    while ( std::getline( istrm, line ) )
    {
        std::istringstream iss( line );
        std::string word;
        while ( iss >> word )
        {
            Token token;
            token.line = line_number;

            if ( word == "(" ) token.type = TokenType::LEFT_PAREN;
            else if ( word == ")" ) token.type = TokenType::RIGHT_PAREN;
            else if ( word == "{" ) token.type = TokenType::LEFT_BRACE;
            else if ( word == "}" ) token.type = TokenType::RIGHT_BRACE;
            else if ( word == "," ) token.type = TokenType::COMMA;
            else if ( word == "." ) token.type = TokenType::DOT;
            else if ( word == ";" ) token.type = TokenType::SEMICOLON;
            else if ( word == "-" ) token.type = TokenType::MINUS;
            else if ( word == "+" ) token.type = TokenType::PLUS;
            else if ( word == "/" ) token.type = TokenType::SLASH;
            else if ( word == "*" ) token.type = TokenType::STAR;
            else if ( word == "%" ) token.type = TokenType::PERCENT;
            else if ( word == "!" ) token.type = TokenType::BANG;
            else if ( word == "!=" ) token.type = TokenType::BANG_EQUAL;
            else if ( word == "=" ) token.type = TokenType::EQUAL;
            else if ( word == "==" ) token.type = TokenType::EQUAL_EQUAL;
            else if ( word == ">" ) token.type = TokenType::GREATER;
            else if ( word == ">=" ) token.type = TokenType::GREATER_EQUAL;
            else if ( word == "<" ) token.type = TokenType::LESS;
            else if ( word == "<=" ) token.type = TokenType::LESS_EQUAL;
            else if ( word == "and" ) token.type = TokenType::AND;
            else if ( word == "or" ) token.type = TokenType::OR;
            
            else if ( word == "class" ) token.type = TokenType::CLASS;
            else if ( word == "var" ) token.type = TokenType::VAR;
            else if ( word == "if" ) token.type = TokenType::IF;
            else if ( word == "else" ) token.type = TokenType::ELSE;
            else if ( word == "while" ) token.type = TokenType::WHILE;
            else if ( word == "for" ) token.type = TokenType::FOR;
            else if ( word == "new" ) token.type = TokenType::NEW;
            else if ( word == "init" ) token.type = TokenType::INIT;
            else if ( word == "this" ) token.type = TokenType::THIS;
            else if ( word == "true" ) token.type = TokenType::TRUE;
            else if ( word == "false" ) token.type = TokenType::FALSE;
            else if ( word == "nil" ) token.type = TokenType::NIL;
            else if ( word == "return" ) token.type = TokenType::RETURN;
            else if ( word == "break" ) token.type = TokenType::BREAK;
            else if ( word == "continue" ) token.type = TokenType::CONTINUE;
            else if ( word == "print" ) token.type = TokenType::PRINT;
            else if ( word == "fun" ) token.type = TokenType::FUN;
            else if ( word == "super" ) token.type = TokenType::SUPER;
            /* TODO: there is an error, if there is a number and then semicolon right after, we are not lexing it correctly */
            else if ( std::isdigit( word[ 0 ] ) || ( word[ 0 ] == '.' && word.length() > 1 && std::isdigit( word[ 1 ] ) ) )
            {
                token.type = TokenType::NUMBER;
            }
            else if ( word[0] == '"' && word.back() == '"' )
            {
                token.type = TokenType::STRING;
            }
            else
            {
                token.type = TokenType::IDENTIFIER;
            }
            
            token.lexeme = word;
            tokens.push_back( token );
        }
        ++line_number;
    }
    
    Token eof_token;
    eof_token.type = TokenType::EOF_TOKEN;
    eof_token.lexeme = "";
    eof_token.line = line_number;
    tokens.push_back( eof_token );
    
    return tokens;
}
