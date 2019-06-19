# this script is a simple R interface to call mlpackMain
# compilation instructions for R.Curtin
# R CMD SHLIB pca_binding.cpp -lmlpack -larmadillo -fopenmp
# -lboost_program_options  -o 
# if R was not built with openmp support compiler will throw error
# loading the shared object into an R session


#to do finish function interface 
#PCA <- function()

# types for R object can be specified on the c side
# or in the call interface e.g. pca <-function (a, b, c, ...)
# .Call("subroutine", as.numeric(a), etc.) 

#.Call("pca_binding")



