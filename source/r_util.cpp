


#include "./r_util.h"
#include <mlpack/prereqs.hpp>
#include <mlpack/core/util/cli.hpp>

using namespace mlpack;

extern "C" {

#include <R.h>
#include <Rinternals.h>
  /**
   *  wrapper function definition to call CLI::RestoreSettings()
   *  for a given program name
   */
void CLI_RestoreSettings(const char* programName)
{
 CLI::RestoreSettings(programName);
}


void CLI_SetParamInt(const char* paramName, int paramValue)
{
  CLI::GetParam<int>(paramName) = paramValue;
  CLI::SetPassed(paramName);
  
}

  void CLI_SetParamDouble(const char* paramName, double paramValue)
  {
    CLI::GetParam<double>(paramName) = paramValue;
    CLI::SetPassed(paramName);

   }

  #include <R_ext/Rdynload.h>

#define CDEF(name, n) {#name, (DL_FUNC) &name, n}

  static const
  R_CMethodDef cEntries[] = {
    CDEF(CLI_RestoreSettings, 1),
    CDEF(CLI_SetParamInt, 2),
    CDEF(CLI_SetParamDouble, 2),
    {NULL, NULL, 0}

  };

  void R_intit_r_util(DllInfo *dll)
  {
    R_registerRoutines(dll, cEntries, NULL, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
    R_forceSymbols(dll, TRUE);
  }

} // extern "C"
