#first run R CMD SHLIB -fopenmp -lmlpack -larmadillo -lboost_program_options r_util.cpp
#run the followinv code to link the compiled code to the R session
dyn.load("r_util.so")

#functions to call underlying compiled code specifying R data types via coercion 

CLIRestoreSettings <- function(programName)
                  .Call("CLI_RestoreSettings",
		        as.character(programName))

CLISetParamInt <- function(paramName, paramValue)
	       	  .Call("CLI_SetParamInt",
			as.character(paramName),
			as.integer(paramValue))

CLISetParamString <- function(paramName, paramValue)
		     .Call("CLI_SetParamString",
			as.character(paramName),
			as.character(paramValue))

CLISetParamBool <- function(paramName, paramValue)
		   .Call("CLI_SetParamBool",
			as.character(paramName),
			as.logical(paramValue))