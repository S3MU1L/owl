#pragma once

#include <string>
#include <iostream>

#include "token.hpp"

bool check_owl_filename( const std::string& filename );

std::string to_string( Token token );

void report( int line, const std::string& where, const std::string msg );

void error( int line, const std::string& msg );
