cmake_minimum_required(VERSION 3.1)
project(StudentCard VERSION 0.1.0 LANGUAGES CXX)
add_executable(main main.cpp mesh.cpp steady_state.cpp heat_conduction_2d.cpp)
set (CMAKE_CXX_FLAGS "-O3 -pg")