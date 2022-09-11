
#ifndef HDLN // {

  # include<stdio.h>  // vsnprintf
  # include<stdarg.h> // va_list, va_start, va_end
  # include<stdint.h> // int64_t
  # include<string.h> // strlen, size_t
  # include<assert.h> // static_assert
  # define HDLN
                  

  #ifdef __cplusplus
     # define ALIGN_AS(x) alignas(x)
     # define RESTRICT 
     # define STATIC_ASSERT static_assert

  #else
    # define ALIGN_AS(x) _Alignas(x)
    # define RESTRICT restrict
    # define STATIC_ASSERT _Static_assert
  
  #endif



  #if defined(__linux__) || defined(__unix__)
     # include<unistd.h>  // write
     # define WRITE write
     # define IS_HDLN_SUPPORT_YOUR_PLATFORM 1
 
  #elif defined(_WIN32)
     # include<io.h>  // _write
     # define WRITE _write
     # define IS_HDLN_SUPPORT_YOUR_PLATFORM 1

  #else
     # define IS_HDLN_SUPPORT_YOUR_PLATFORM 0

  #endif
  
  
  // function prototype..
  size_t puthdln(const char* const str);             
  size_t printhdln(const char* RESTRICT fmt, ...);  

// }
#endif
