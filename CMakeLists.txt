cmake_minimum_required(VERSION 3.5)

project(randomNumGen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES_GEN
        src/congurent_generator.cpp
        src/fibonacci_generator.cpp
        src/mersenne_twister.cpp
    )

set(HEADERS_GEN
        include/fibonacci_generator.hpp
        include/congurent_generator.hpp
        include/mersenne_twister.hpp
    )

add_library(randomgenlib ${HEADERS_GEN} ${SOURCES_GEN})

set(HEADERS_MET
        include/metrics.hpp
    )
set(SOURCES_MET
        src/metrics.cpp
    )
add_library(metricslib ${HEADERS_MET} ${SOURCES_MET})

include_directories(include)

add_executable(main src/main.cpp)
target_link_libraries(main randomgenlib
                           metricslib
                           )
