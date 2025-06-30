#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/lexer.hpp"
#include "../include/util.hpp"

int main( int argc, char* argv[] )
{
    if ( argc != 2 )
    {
        std::cerr << "Usage: " << "./owl filename.ow" << '\n';
        return 1;
    }

    if ( !has_suffix( argv[ 1 ], ".ow" ) )
    {
        std::cerr<< "File suffix is not .ow" << '\n';
        std::cerr<< "Please provide a valid Owl file." << '\n';
        return 1;
    }

    try
    {
        Lexer lex{ argv[1] };
        const auto& tokens = lex.scan_tokens();
        for ( const auto& token : tokens )
            std::cout<< to_string( token ) << '\n';   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
