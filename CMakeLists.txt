cmake_minimum_required(VERSION 3.14)
project(MatrizDispersa)

set(CMAKE_CXX_STANDARD 17)

add_executable(MatrizDispersa main.cpp SparseMatrix.cpp SparseMatrix.h)