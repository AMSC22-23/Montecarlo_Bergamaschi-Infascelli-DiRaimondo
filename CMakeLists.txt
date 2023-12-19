cmake_minimum_required(VERSION 3.12.0)
project(MONTECARLO_BERGAMASCHI-INFASCELLI-DIRAIMONDO CXX C)

find_package(muparser CONFIG REQUIRED HINTS ./muparser)
set(muparser_INCLUDE ${muparser_DIR}/../../../include)
set(muparser_LIB ${muparser_DIR}/../..)

set(SOURCES
    src/main.cpp
    src/Domain.hpp
    src/HyperSphere.cpp
    src/HyperRectangle.cpp
    src/MontecarloIntegration.cpp
    src/MontecarloIntegration.hpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE src ${muparser_INCLUDE})
target_link_libraries(${CMAKE_PROJECT_NAME} -L${muparser_LIB} -lmuparser)