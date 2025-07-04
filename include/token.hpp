#pragma once

#include <string>

enum class TokenType;

struct Token
{
    TokenType type;
    std::string lexeme;
    int line;
};

enum class TokenType
{
    /* Single-character tokens */
    LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACE, RIGHT_BRACE,
    LEFT_BRACKET, RIGHT_BRACKET,
    COMMA, DOT, SEMICOLON, COLON,

    /* Operators */
    MINUS, PLUS, SLASH, STAR, PERCENT,
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,
    AND, OR,

    /* Literals */
    IDENTIFIER, STRING, NUMBER,

    /* Special tokens */
    COMMENT, NEWLINE,

    /* Keywords */
    CLASS, VAR, IF, ELSE,
    WHILE, FOR, NEW, INIT,
    THIS, TRUE, FALSE, NIL,
    RETURN, BREAK, CONTINUE,
    PRINT, FUN, SUPER,

    /* Type keywords */
    INT, STRING_TYPE, BOOL, FLOAT, DOUBLE, VOID,

    /* End-of-file */
    EOF_TOKEN
};