cmake_minimum_required(VERSION 3.25)
project(zad2)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.74.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest main.cpp)
target_link_libraries(BoostTest ${Boost_LIBRARIES})
add_executable(zad2 main.cpp Graph.h Graph.cpp)
