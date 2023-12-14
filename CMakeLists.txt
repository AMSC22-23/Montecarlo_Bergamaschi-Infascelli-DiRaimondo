cmake_minimum_required(VERSION 3.12.0)
project(MONTECARLO_BERGAMASCHI-INFASCELLI-DIRAIMONDO CXX C)

include(../common/cmake-common.cmake)

# Use find_path for muparser include directory
find_path(MUPARSER_INCLUDE_DIR NAMES muParser.h PATHS /muparser-2.3.4/include)

# Use find_library for muparser library
find_library(MUPARSER_LIB NAMES muparser PATHS /muparser-2.3.4/lib)

# Check if muparser was found
if(NOT MUPARSER_INCLUDE_DIR OR NOT MUPARSER_LIB)
    message(FATAL_ERROR "muparser not found. Please check the paths.")
endif()

find_package(muparser REQUIRED)
set(SOURCES
    src/main.cpp
    src/Domain.hpp
    src/HyperSphere.cpp
    src/HyperRectangle.cpp
    src/MontecarloIntegration.cpp
    src/MontecarloIntegration.hpp
)

add_executable(MONTECARLO_BERGAMASCHI-INFASCELLI-DIRAIMONDO ${SOURCES})

target_include_directories(MONTECARLO_BERGAMASCHI-INFASCELLI-DIRAIMONDO PRIVATE src ${MUPARSER_INCLUDE_DIRS} /muparser-2.3.4/include)

target_link_libraries(MONTECARLO_BERGAMASCHI-INFASCELLI-DIRAIMONDO PRIVATE ${MUPARSER_LIBRARIES})