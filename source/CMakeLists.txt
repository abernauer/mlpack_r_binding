#file specifying directory and project hierarchy 

#specifying required version of cmake
cmake_minimum_required(VERSION 3.10)


#sets project name accepts 
project(mlpack_r_binding)

#specifies target executable to build and source files 
add_executable(r_print_pca pca_binding.cpp)

string(APPEND CMAKE_CXX_FLAGS "-fopenmp -lmlpack -lboost_program_options")

find_library(MLPACK_LIB_DIR libmlpack.so /usr/local/lib/)
