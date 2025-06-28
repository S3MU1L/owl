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

    if ( !check_owl_filename( argv[ 1 ] ) )
        return 1;
    

    try
    {
        const auto& tokens = get_tokens( argv[ 1 ] );
        for ( const auto& token : tokens )
            std::cout<< to_string( token ) << '\n';   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
