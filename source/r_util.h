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


   void CLI_SetParamVectorInt(const char* paramName,
			      uint64_t* ints,
			      const size_t length);

   
#if defined(__cplusplus) || defined(c_plusplus)
 }
#endif

#endif
