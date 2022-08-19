
#ifndef HDLN // {

  # include<stdio.h>  // vsnprintf
  # include<stdarg.h> // va_list, va_start, va_end
  # include<stdint.h> // int64_t
  # include<string.h> // strlen, size_t
  # define HDLN
                  

  #ifdef __cplusplus
     # define ALIGN_AS(x) alignas(x)
     # define RESTRICT 

  #else
    # define ALIGN_AS(x) _Alignas(x)
    # define RESTRICT RESTRICT
  
  #endif



  #if defined(__linux__) || defined(__unix__)
     # include<unistd.h>  // write
     # define WRITE write
 
  #elif defined(_WIN32)
     # include<io.h>  // _write
     # define WRITE _write

  #endif
  
  
  // function prototype..
  size_t puthdln(const char* const str);             
  size_t printhdln(const char* RESTRICT fmt, ...);  

// }
#endif
