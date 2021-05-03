cmake_minimum_required(VERSION 3.16)
project(CS372CPS)

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.x)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 20)

set(Warnings, $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra -Wpedantic -Weverything>
        $<$<CXX_COMPILER_ID:MSVC>:
        /W4>)

add_executable(CS372CPS main.cpp Shape.cpp Shape.hpp)
target_compile_options(CS372CPS PRIVATE ${Warnings})

add_executable(tests testsmain.cpp tests.cpp Shape.cpp Shape.hpp)
target_compile_options(tests PRIVATE ${Warnings})
target_link_libraries(tests PRIVATE Catch2::Catch2)

