#file specifying directory and project hierarchy 

#sets project name accepts 
project(mlpack_r_binding)

#specifies target executable to build and source files 
add_executable(r_print_pca pca_binding.cpp)

find_library(MLPACK_LIB_DIR libmlpack.so /usr/local/lib/)
