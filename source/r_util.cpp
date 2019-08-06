


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

} // extern "C"
