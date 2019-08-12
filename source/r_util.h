/** 
 * r_util.h
 *
 *
 * Utility functions in C that can be called from R with call() interface in 
 * order to with the CLI interface.
 */
 #ifndef MLPACK_BINDINGS_R_R_UTIL_H
 #define MLPACK_BINDINGS_R_R_UTIL_H

 #if defined(__cplusplus) || defined(c_plusplus)

 #include <cstddef>
 #include <cstdint>
 extern "C"
 {
 #else
 #include <stddef.h>
 #include <stdint.h>
 #endif

  /**
   * Call CLI::RestoreSettings() for a given program name.
   */
  void CLI_RestoreSettings(const char* programName);

   /**
    * Call CLI::SetParam<int>
    */
   void CLI_SetParamInt(const char* paramName, int paramValue);



   void CLI_SetParamDouble(const char* paramName, double paramValue);



   void CLI_SetParamString(const char* paramName, const char* paramValue);



   void CLI_SetParamBool(const char* paramName, bool paramValue);



   void CLI_SetParamVectorStrLen(const char* paramName,
				 const size_t length);


   

   void CLI_SetParamVectorStrStr(const char* paramName,
				 const char* str,
				 const size_t element);

   void CLI_SetParamVectorInt(const char* paramName,
			      uint64_t* ints,
			      const size_t length);

   void CLI_SetParamMat(const char* paramName,
			double* memptr,
			const size_t rows,
			const size_t cols,
			const bool pointsAsRows);

   void CLI_SetParamUMat(const char* paramName,
			 size_t* memptr,
			 const size_t rows,
			 const size_t cols,
			 const bool pointsAsRows);

   void CLI_setParamRow(const char* paramName,
			double* memptr,
			const size_t cols);

   void CLI_SetParamURow(const char* paramName,
			 size_t* memptr,
			 const size_t cols);

   void CLI_SetParamCol(const char* paramName,
			double* memptr,
			const size_t rows);

   void CLI_SetParamMatWithInfo(const char* paramName,
				bool* dimensions,
				double* memptr,
				const size_t rows,
				const size_t cols,
				const bool pointsAreRows);

   int CLI_GetParamInt(const char* paramName);

   double CLI_GetParamDouble(const char* paramName);

   const char* CLI_GetParamString(const char* paramName);

   bool CLI_GetParamBool(const char* paramName);

   size_t CLI_GetParamVectorStrLen(const char* paramName);

   const char* CLI_GetParamVectorStrStr(const char* paramName, const int i);

   size_t CLI_GetParamVectorIntLen(const char* paramName);

   uint64_t* CLI_GetParamVectorIntPtr(const char* paramName);

   size_t CLI_GetParamMatRows(const char* paramName);

   size_t CLi_GetParamMatCols(const char* paramName);

   double* CLI_GetParamMat(const char* paramName);

   size_t CLI_getParamUMatRows(const char* paramName);

   size_t CLI_getParamUMatCols(const char* paramName);

   size_t* CLI_GetParamUMat(const char* paramName);

   size_t CLI_GetParamColRows(const char* paramName);

   double* CLI_GetParamCol(const char* paramName);

   size_t CLI_GetParamURowCols(const char* paramName);

   size_t* CLI_GetParamURow(const char* paramName);

   size_t CLI_GetParamMatWithInfoRows(const char* paramName);

   size_t CLI_GetParamMatWithInfoCols(const char* paramName);

   bool* CLI_GetParamMatWithInfoBoolPtr(const char* paramName);

   double* CLI_GetParamMatWithInfoPtr(const char* paramName);

   void CLI_EnableVerbose();

   void CLI_DisabelVerbose();

   void CLI_ResetTimers();

   void CLI_SetPassed(const char* paramName);
   

   
#if defined(__cplusplus) || defined(c_plusplus)
 }
#endif

#endif
