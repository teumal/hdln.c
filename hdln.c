

# include"hdln.h"

// check your platform.
static_assert(IS_HDLN_SUPPORT_YOUR_PLATFORM, 
              "\"hdln\" is not supported your platform");


// write the headline to the output stream stdout.
size_t puthdln(const char* const str) {
	
    #define __PUTHDLN__OUT_FLUSH if( (char*)in>=(out+1024) ) {    \
   	                             ret += WRITE(1, out, 1024);  \
   	                             in = (int64_t*) out;         \
   	                         } 
	
         ALIGN_AS(64)  static const char data[] = {
		//   0         1         2        3         4         5           6        7         8             9        10        11         12       13        14        15        16        17        18        19         20       21        22        23        24        25         26        27        28       29        30        31        32        33        34        35        36        37        38       39        40        41        42         43        44       45         46        47        48        49        50        51        52        53       54         55        56        57         58        59       60        61       62        63         64        65        66        67       68        69         70        71       72        73         74        75        76       77         78        79         80       81        82        83        84         85        86      87         88        89        90       91        92         93        94        95        96         97       98        99        100      101        102       103       104      105       106       107        108      109       110        111      112       113        114      115        116       117       118      119        120       121      122        123       124       125       126        127
		//  NUL      SOH        STX      ETX       EOT       ENQ       ACK       BEL        BS           HT         LF         VT         FF       CR         SO        SI       DLE       DC1       DC2       DC3       DC4       NAK       SYN       ETB        CAN       EM       SUB       ESC       FS        GS         RS        US      (space)     !          "        #         $         %        &          '         (         )         *         +         ,         -         .          /        0         1        2          3          4        5         6         7         8          9        :         ;         <         =         >         ?         @         A         B         C         D         E         F         G         H         I         J          K        L         M         N         O         P          Q         R        S         T         U         V         W         X          Y        Z        [          \         ]         ^         _         `         a         b         c         d          e        f          g        h          i        j          k        l         m         n         o          p        q          r        s         t         u         v         w         x         y         z         {          |       }           ~       DEL
		"        ""        ""        ""        ""        ""        ""        ""        ""        ""   \t\t\t\t\t""       \n""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""  __    ""  _  _  ""        ""   ||_  ""        ""  __    ""   _    ""  ___   "" ___    ""        ""        ""        ""        ""        ""      _ "" _____  ""   _    "" _____  "" ___    ""    /|  ""   ___  ""  ___   ""______  ""  ___   ""  ___   ""        ""   __   ""     _  ""        "" _      ""  ___   ""  ____  "" _____  "" _____  ""  ___   "" ____   ""  ___   "" _____  ""  ____  "" _   _  "" _____  "" _____  "" __  __ "" _      "" _   _  "" ___   _"" ______ "" ____   "" ______ "" ____   ""  ____  ""_______ "" _   _  "" _   _  "" _   _  "" __  __ "" __  __ "" _____  "" ___    ""_       "" ___    ""        ""        ""_       ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""   __   ""   __   ""   __   ""        ""        "
		"        ""        ""        ""        ""        ""        ""        ""        ""        ""   \t\t\t\t\t""       \n""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        "" |  |   "" |_||_| "" _//_//_""  /  _] "" _   __ "" (  )   ""  |_|   "" / __|  ""|__ )   ""  ____  ""   _    ""        ""        ""        ""     / /""/  _  L ""__| |   ""/ __  ) ""/_  )   ""   / |  ""  /  _] "" / __|  ""|     | "" /   )  "" /    ) ""   _    ""  |__|  ""    / / "" _____  "" L L    "" (   |  "" ( __ )_""/     | ""|     ) "" /  _]  ""|    )  "" /   _] ""|  ___] "" /  __] ""| | | | ""|_   _| ""|_   _| ""|  |/ / ""| |     ""| |_| | ""|   ) /|""/ ____ )""|    )  ""/ ____ )""|    )  "" / __ | ""|_   _| ""| | | | ""| | | | ""| |^| | ""[_|  | ]""[ |  | ]""[____ | ""|  _|   ""L|      ""|_  |   ""  //LL  ""        ""LL      ""  ____  "" _      ""  ___   ""      _ ""  ____  ""   __   ""  ____  "" _      ""  _     ""  _     "" _      ""  _     ""        ""        ""        "" _  __  "" __ _   "" _      "" ___    ""  _     "" _   _  "" _   _  "" _ ___  "" _   _  "" _   _  "" _____  ""  / _|  ""  |  |  ""  |_ ]  ""        ""        "
		"        ""        ""        ""        ""        ""        ""        ""        ""        ""   \t\t\t\t\t""       \n""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        "" |  |   ""        "" - -- --"" /  |_  ""|_| / / ""( O  )  ""        ""/ /     ""   ) )  "" (_||_) "" _| |_  ""        "" _____  ""        ""    / / ""| / ) | ""|_  |   ""|_| / / "" _|  )  ""  /  |_ "" /  /_  ""/ <__   ""| __  | ""(  O  ) ""( O   ) ""  |_|   ""   __   ""   / /  ""|_____| ""  L L   ""(_/| /  ""( /  L//""|  0  | ""|  0  ) ""/  |    ""|     ) ""/   |_  ""|  |__  ""/  /___ ""| |_| | ""  | |   ""  | |   ""|  | /  ""| |     ""| | | | ""|  _ | |""(/    ))""| D   ) ""(/    ))""| D   ) ""/ /__|| ""  | |   ""| | | | ""| | | | ""| | | | ""  LL_// ""[ L__| ]""    / / ""| |     "" L|     ""  | |   "" //  LL ""        ""        "" /___ ) ""| |     "" / __|  ""     | |"" /    ) ""  /__|  "" / O _| ""| |     "" |_|    "" |_|    ""| | _   "" | |    "" __ ___ ""____    "" _____  ""| |/  ) ""(  V |  ""| |___  ""/ __|   ""_| |_   ""| | | | ""| | | | ""| | | | ""| | | | ""| | | | ""|___  | "" | /    ""  |  |  ""   _> > "" ___    ""        "
		"        ""        ""        ""        ""        ""        ""        ""        ""        ""   \t\t\t\t\t""       \n""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        "" |  |   ""        ""_//_//_ "" |_   | ""   / /  ""(_   )  ""        ""( |     ""   | )  "" (_  _) ""|_   _| ""        ""|_____| ""        ""   / /  ""| | | | ""  | |   ""   / /  ""[__  |  "" /  o  |"" |__  | ""|    )  ""|_| | | "" >   <  "" L_   / ""   _    ""  |_ |  ""  / /   "" _____  ""   L L  "" |-_/   ""(| 0  /)""|     | ""|    <  ""|  |    ""|  D  ) ""|    _] ""|  ___] ""|  |L | ""|  _  | ""  | |   ""  | |   ""|   /_  ""| |___  ""|     | ""|  | | |""(|    |)""|   _)  ""(|   _|)""|    )  ""L___  ) ""  | |   ""| |_| | ""| |_| | ""|     | ""   | |  "" L    / ""   / /  ""| |     ""  L|    ""  | |   ""        ""        ""        "" ___/ | ""| |     ""/  |    ""  __ | |""|  O   )""_/ |_   ""|___/   ""| |___  ""  _     ""____    ""| |/ /  "" | |    ""|/ | || ""| _ )   ""| ___ | ""|   O ) ""( O  |  ""| / __| ""L L_    ""|_  _|  ""| | | | ""| | | | ""| | | | ""|_ V  / ""|_ V  | ""   / /  "" / _|   ""  |  |  ""  |_ <  ""/ __|_//""        "
		"        ""        ""        ""        ""        ""        ""        ""        ""        ""   \t\t\t\t\t""       \n""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        "" |__|   ""        ""- -- -- ""  _|| | ""  / /_  "" (  )_  ""        ""( |     ""   | )  "" (_||_) ""  |_|   "" __     ""        ""        ""  / /   ""| | | | ""  | |   ""  / /   "" _|  |  ""[___  _|""    | | ""|  O  ) ""    | | ""(  0  ) ""   / /  ""  |_|   ""    ||  "" / /___ ""|_____| "" ___L L "" ||     ""( L _/ )""|  -  | ""|  0  ) ""|  |_   ""|     ) ""|   |_  ""|  |    ""|  |/ | ""| | | | ""  | |   ""__| |   ""|   _ L ""|     | ""| | | | ""|  | | |""(|    |)""|  |    ""(|  |||)""| _ <   "" _  | | ""  | |   ""|     | ""|     | ""|  |  | "" _/ _ L ""  |  |  ""  / /   ""| |     ""   L|   ""  | |   ""        ""        ""        ""/     | ""|  L__  ""|  |    "" /  L| |""| ____/ ""|   _|  ""  //__  ""| /   ) "" | |    ""|__ |   ""|   /   "" | |    ""|     | ""| | |   ""||   || ""|  __/  "" L__ |  ""|  /    "" L_ L   "" | |    ""| |_| | ""|  V  | ""|     | "" | _ |  ""  L__ | ""  / /   ""< |_    ""  |  |  ""   _> > ""|/ |__/ ""        "
		"        ""        ""        ""        ""        ""        ""        ""        ""        ""   \t\t\t\t\t""       \n""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""  __    ""        ""// //   "" |_  _| "" /_/|_| ""( O | | ""        ""(  L_   "" __) )  ""        ""        ""|_ |    ""        ""  _     "" / /    ""| |_/ / ""  | |   "" / /___ ""|    |  ""    | | ""  __| | ""|     ) ""    | | ""(     / ""  / /   ""        ""        ""/______|""        ""|_____> ""        "" (____) ""|  |  | ""|     ) ""|    |  ""|     ) ""|     | ""|  |    ""|     | ""| | | | "" _| |_  ""||| |   ""|  | ) ]""|     | ""| |_| | ""|  |   |""(L____/)""|  |    ""(|__/  |""| || )  ""| |_| | ""  | |   ""|     | "" L   /  ""[  |  ] ""|  / | |""  |  |  "" / /__  ""| |_    ""    L|  "" _| |   ""        "" ______ ""        ""| o   | ""|  D  ) ""|  |_   ""( D    |""| |____ "" | |    "" / O  ) ""|  /| | "" | |    "" _) |   ""| |) )  "" | L.   ""|  | || ""| | |   ""||___|| ""| |     ""   | |  ""| |     ""||_)|   "" | |_   ""|     | ""|_   _| ""|     | ""/ / | | ""   _/ | "" / /__  "" |_ |_  ""  |  |  ""  |  |  ""        ""        "
		"        ""        ""        ""        ""        ""        ""        ""        ""        ""   \t\t\t\t\t""       \n""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        ""        "" |__|   ""        ""        ""   ||   ""        "" (____| ""        "" L___|  ""|___)   ""        ""        ""  ||    ""        "" |_|    ""/_/     "" L___/  ""  |_|   ""(_____| ""|___/   ""    |_| "" |____| "" L___/  ""    |_| "" L___/  "" /_/    ""        ""        ""        ""        ""        "" []     ""        ""|__|__| ""|____/  ""|____|  ""|____/  ""|_____| ""|__|    "" L___/  ""|_| |_| ""|_____| ""L__/    ""|__| )_]""|_____| ""|_| |_| ""|__|L__|""L_____/ ""|__|    ""(____/L|""|_||_|  ""|_____| ""  |_|   ""|_____| ""  [_/   "" L_|_/  ""|_|  L_|""  |__|  ""[_____| ""|___|   ""     L| ""|___|   ""        ""|______|""        ""|___/|| ""|____/  ""|____|  "" L___/||"" L____/ "" |_|    "" |___/  ""|_| |_| "" |_|    ""|__/    ""|_||_|  "" (__|   ""|__|_|| ""|_|_|   ""|_____| ""|_|     ""   |_|  ""|_|     ""|___/   "" |___|  "" L__/|| ""  |_|   "" L|_|/  ""|_| |_| ""  |__/  ""/_____| ""  |__|  ""  |__|  ""  |_|   ""        ""        "
	};
	
	ALIGN_AS(8) char out[1024];
	
	int64_t*     in    = (int64_t*) out;
	const size_t strsz = strlen(str);
	int    handle_lf = 0;
	size_t ret       = 0;
        size_t begin     = 0; 
 
HANDLE_LF:

   	for(int i=0; i<7; ++i) {
   	    for(size_t j=begin; j<strsz; ++j) {
   	        const char c = str[j];
   	        
   	        if(c=='\n') {
   	            if(i==6) {
   	              begin     = j+1;
   	              handle_lf = 1; 
   	            }
   	            break;
   	        }
   	        *in++ = ( (int64_t(*)[128]) data )[i][c];
   	        __PUTHDLN__OUT_FLUSH
   	    }
   	    *in++ = 0xa20202020202020;  // "       \n"
   	    __PUTHDLN__OUT_FLUSH
   	}
   	
   	if(handle_lf) {
   	    handle_lf = 0;
   	    goto HANDLE_LF;
   	}
   	
   	if( (char*)in>out) {
   	    ret += WRITE(1, out, (char*)in - out);
   	}
   	
   	return ret;
}



/************************************************
* - Conversion Specifier -
* 
*  []:optional, (): necessary
*
*
*  %[flag][width][.precision][length](speicifier)
*
*   flag      : -, +, (space), #, 0
*
*   width     : integer value, *
*
*   precision : .integer value
*
*   length    : hh, h, (none), l, ll, j, z, t, L
*
*   specifier : %, c, s, d, i, o, x, X, u, f, F, e, E, a, A, g, G, n, p
*
************************************************/


// write the result to the output stream stdout.
// you can use this function as the printf function
size_t printhdln(const char* RESTRICT fmt, ...) {
    char buf[2048];
    va_list argp;
    va_start(argp, fmt);
    vsnprintf(buf, 2048, fmt, argp);
    va_end(argp);
    return puthdln(buf);
}







