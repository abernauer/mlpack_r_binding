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