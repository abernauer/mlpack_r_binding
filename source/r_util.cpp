


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

  void CLI_SetParamString(const char* paramName, const char* paramValue)
  {
    CLI::GetParam<std::string>(paramName) = paramValue;
    CLI::SetPassed(paramName);
  }

  void CLI_SetParamBool(const char* paramName, bool paramValue)
  {
    CLI::GetParam<bool>(paramName) = paramValue;
    CLI::SetPassed(paramName);
  }

  void CLI_SetParamVectorStrLen(const char* paramName,
				const size_t length)
  {
    CLI::GetParam<std::vector<std::string>>(paramName).clear();
    CLI::GetParam<std::vector<std::string>>(paramName).resize(length);
    CLI::SetPassed(paramName);
  }

  void CLI_SetParamVectorStrStr(const char* paramName,
				const char* str,
				const size_t element)
  {
    CLI::GetParam<std::vector<std::string>>(paramName)[element] =
      std::string(str);
  }

  void CLI_SetParamVectorInt(const char* paramName,
			     uint64_t* ints,
			     const size_t length)
  {

    std::vector<int> vec(length);
    for (size_t i = 0; i < (size_t) length; ++i)
      vec[i] = ints[i];

    CLI::GetParam<std::vector<int>>(paramName) = std::move(vec);
    CLI::SetPassed(paramName);
  }

  void CLI_SetParamMat(const char* paramName,
		       double* memptr,
		       const size_t rows,
		       const size_t cols,
		       const bool pointsAsRows)
  {

    arma::mat m(memptr, rows, cols, false, true);
    CLI::GetParam<arma::mat>(paramName) = pointsAsRows ? m.t() : std::move(m);
    CLI::SetPassed(paramName);
  }

  void CLI_SetParmUMat(const char* paramName,
		       size_t* memptr,
		       const size_t rows,
		       const size_t cols,
		       const bool pointsAsRows)
  {
    arma::Mat<size_t> m(memptr, rows, cols, false, true);
    CLI::GetParam<arma::Mat<size_t>>(paramName) = pointsAsRows ? m.t() :
      std::move(m);
    CLI::SetPassed(paramName);
  }

  void CLI_SetParamRow(const char* paramName,
		       double* memptr,
		       const size_t cols)
  {
    arma::rowvec m(memptr, cols, false, true);
    CLI::GetParam<arma::rowvec>(paramName) = std::move(m);
    CLI::SetPassed(paramName);
  }

  void CLI_SetParamURow(const char* paramName,
		        size_t* memptr,
			const size_t cols)
  {
    arma::Row<size_t> m(memptr, cols, false, true);
    CLI::GetParam<arma::Row<size_t>>(paramName) = std::move(m);
    CLI::SetPassed(paramName);
  }

  
  void CLI_SetParamCol(const char* paramName,
		       double* memptr,
		       const size_t rows)
  {
    arma::vec m(memptr,rows, false, true);
    CLI::GetParam<arma::vec>(paramName) = std::move(m);
    CLI::SetPassed(paramName);
  }

  void CLI_SetParamMatWithInfo(const char* paramName,
			       bool* dimensions,
			       double* memptr,
			       const size_t rows,
			       const size_t cols,
			       const bool pointsAreRows)
  {
    data::DatasetInfo d(pointsAreRows ? cols : rows);
    for (size_t i = 0; i < d.Dimensionality(); ++i)
      {
	d.Type(i) = (dimensions[i]) ? data::Datatype::categorical :
	  data::Datatype::numeric;
      }

    arma::mat m(memptr, rows, cols, false, true);
    std::get<0>(CLI::GetParam<std::tuple<data::DatasetInfo, arma::mat>>(
	 paramName)) = std::move(d);
    std::get<1>(CLI::GetParam<std::tuple<data::DatasetInfo, arma::mat>>(
	 paramName)) = pointsAreRows ? std::move(m.t()) : std::move(m);
    CLI::SetPassed(paramName);
  }

  bool CLI_GetParamBool(const char* paramName)
  {
    return CLI::GetParam<bool>(paramName);
  }

  size_t CLI_GetParamVectorStrLen(const char* paramName)
  {
    return CLI::GetParam<std::vector<std::string>>(paramName).size();
  }

  const char* CLI_GetParamVectorStrStr(const char* paramName, const int i)
  {
    return CLI::GetParam<std::vector<std::string>>(paramName)[i].c_str();
  }

  size_t CLI_GetParamVectorIntLen(const char* paramName)
  {
    return CLI::GetParam<std::vector<int>>(paramName).size();
  }

  uint64_t* CLI_GetParamVectorIntPtr(const char* paramName)
  {
    const size_t size = CLI::GetParam<std::vector<int>>(paramName).size();
    uint64_t* ints = new uint64_t[size];

    for (size_t i = 0; i < size; ++i)
      ints[i] = CLI::GetParam<std::vector<int>>(paramName)[i];

    return ints;
  }

  size_t CLI_GetParamMatRows(const char* paramName)
  {
    return CLI::GetParam<arma::mat>(paramName).n_rows;
  }

  size_t CLI_GetParamMatCols(const char* paramName)
  {
    return CLI::GetParam<arma::mat>(paramName).n_cols;
  }

  double* CLI_GetParamMat(const char* paramName)
  {
    arma::access::rw(CLI::GetParam<arma::mat>(paramName).mem_state) = 1;
    return CLI::GetParam<arma::mat>(paramName).memptr();
  }

  double CLI_GetParamDouble(const char* paramName)
  {
    return CLI::GetParam<double>(paramName);
  }

  const char* CLI_GetParamString(const char* paramName)
  {
    return CLI::GetParam<std::string>(paramName).c_str();
  }


  size_t CLI_GetParamColRows(const char* paramName)
  {
    return CLI::GetParam<arma::vec>(paramName).n_rows;
  }

  double* CLI_GetParamCol(const char* paramName)
  {
    arma::access::rw(CLI::GetParam<arma::vec>(paramName).mem_state) = 1;
    return CLI::GetParam<arma::vec>(paramName).memptr();
  }

size_t CLI_GetParamUColRows(const char* paramName)
{
  return CLI::GetParam<arma::Col<size_t>>(paramName).n_rows;
}

size_t* CLI_GetParamUCol(const char* paramName)
{
  arma::access::rw(CLI::GetParam<arma::Col<size_t>>(paramName).mem_state) = 1;
  return CLI::GetParam<arma::Col<size_t>>(paramName).memptr();
}

size_t CLI_GetParamRowCols(const char* paramName)
{
  return CLI::GetParam<arma::rowvec>(paramName).n_cols;
}

double* CLI_GetParamRow(const char* paramName)
{
  arma::access::rw(CLI::GetParam<arma::mat>(paramName).mem_state) = 1;
  return CLI::GetParam<arma::mat>(paramName).memptr();

}

size_t CLI_GetParamUMatRows(const char* paramName)
{
  return CLI::GetParam<arma::Mat<size_t>>(paramName).n_rows;
}

size_t CLI_GetParamUMatCols(const char* paramName)
{
  return CLI::GetParam<arma::Mat<size_t>>(paramName).n_cols;
}

size_t CLI_GetParamColsRows(const char* paramName)
{
  return CLI::GetParam<arma::vec>(paramName).n_rows;
}


size_t CLI_GetParamURowCols(const char* paramName)
{
  return CLI::GetParam<arma::Row<size_t>>(paramName).n_cols;
}

size_t* CLI_GetParamURow(const char* paramName)
{
  arma::access::rw(CLI::GetParam<arma::Row<size_t>>(paramName).mem_state) = 1;
  return CLI::GetParam<arma::Row<size_t>>(paramName).memptr();
}

size_t CLI_GetParamMatWithInfoRows(const char* paramName)
{
  return std::get<1>(CLI::GetParam<std::tuple<data::DatasetInfo, arma::mat>>(
	  paramName)).n_rows;

}

  size_t CLI_GetParamMatWithInfoCols(const char* paramName)
  {
    return std::get<1>(CLI::GetParam<std::tuple<data::DatasetInfo, arma::mat>>(
									       paramName)).n_cols;

  }

  bool* CLI_GetParamMatWithInfoBoolPtr(const char* paramName)
  {
    const data::DatasetInfo& d = std::get<0>(
					     CLI::GetParam<std::tuple<data::DatasetInfo, arma::mat>>(paramName));

    bool* dims = new bool[d.Dimensionality()];
    for (size_t i=0; i < d.Dimensionality(); ++i)
      dims[i] = (d.Type(i) == data::Datatype::numeric) ? false : true;

    ////    return dims;
  }


  double* CLI_GetParamMatWithInfoPtr(const char* paramName)
  {
    arma::mat& m = std::get<1>(
			       CLI::GetParam<std::tuple<data::DatasetInfo, arma::mat>>(paramName));
    arma::access::rw(m.mem_state) = 1;
    return m.memptr();
  }

void CLI_EnableVerbose()
{
  Log::Info.ignoreInput = false;
}

void CLI_DisableVerbose()
{
  Log::Info.ignoreInput = true;
}

void CLI_ResetTimers()
{
  CLI::GetSingleton().timer.Reset();
}

void CLI_SetPassed(const char* paramName)
{
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
