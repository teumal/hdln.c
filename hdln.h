
#ifdef HDLN // {

# include<stdint.h> // int64_t
# include<string.h> // strlen, size_t
# define HDLN
                  

#ifdef __cplusplus
   # define ALIGN_AS(x) alignas(x)

#else
  # define ALIGN_AS(x) _Alignas(x)
  
#endif



#if defined(__linux__) || defined(__unix__)
   # include<unistd.h>  // write
   # define WRITE write
 
#elif defined(_WIN32)
   # include<io.h>  // _write
   # define WRITE _write

#endif

// }
#endif
