cmake_minimum_required(VERSION 3.5)

project(randomNumGen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        src/congurent_generator.cpp
        src/fibonacci_generator.cpp
        src/mersenne_twister.cpp
        src/metrics.cpp
        src/main.cpp
    )
set(HEADERS
        include/constexpr_pow.hpp
        include/fibonacci_generator.hpp
        include/congurent_generator.hpp
        include/metrics.hpp
        include/mersenne_twister.hpp
    )

include_directories(include)

add_executable(randomNumGen ${HEADERS} ${SOURCES})
