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
    COMMA, DOT, SEMICOLON,

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
    COMMENT,

    /* Keywords */
    CLASS, VAR, IF, ELSE,
    WHILE, FOR, NEW, INIT,
    THIS, TRUE, FALSE, NIL,
    RETURN, BREAK, CONTINUE,
    PRINT, FUN, SUPER,

    /* End-of-file */
    EOF_TOKEN
};