add_executable(owl 
    main.cpp
    lexer.cpp
    ast.cpp
    parser.cpp
    interpreter.cpp
    value.cpp
    util.cpp
)

target_include_directories(owl PRIVATE ${CMAKE_SOURCE_DIR}/include)
