# this script is a simple R interface to call mlpackMain
# compilation instructions for R.Curtin
# R CMD SHLIB pca_binding.cpp -lmlpack -larmadillo -fopenmp
# -lboost_program_options  -o pca_binding
# if R was not built with openmp support compiler will throw warning
# loading the shared object into an R session
# $R
# then the following uncommented in an R session

# loads the executable into the R session in a portable manner
dyn.load(paste("pca_binding", .Platform$dynlib.ext, sep=""))

# should return TRUE
is.loaded(paste("pca_binding", .Platform$dynlib.ext, sep=""))

# calls mlpacks main function
.Call("mlpackMain", 0)

#to do finish function interface 
#PCA <- function() {

# types for R object can be specified on the c side
# or in the call interface e.g. pca <-function (a, b, c, ...)
# .Call("subroutine", as.numeric(a), etc.) 

#.Call("pca_binding")

#}


