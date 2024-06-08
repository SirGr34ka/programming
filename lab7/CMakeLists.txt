cmake_minimum_required( VERSION 3.14 )
project( lab7 CXX )
set( CMAKE_CXX_STANDARD 17 )
set( CXX_STANDARD_REQUIRED TRUE )

if( MSVC )
    add_compile_options( /W4 /WX )
else()
    add_compile_options( -Wall -Wextra -pedantic -Werror -g )
endif()

enable_testing()
add_subdirectory( gtests )