#pragma once

#include <string>
#include <iostream>

#include "token.hpp"

bool has_suffix( const std::string& str, const std::string& suffix );

std::string to_string( Token token );

void report( int line, const std::string& where, const std::string msg );

void error( int line, const std::string& msg );
