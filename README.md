# hdln.c
write a headline string to stdout stream

문자열을 제목으로 바꾸어 출력합니다. 각 문자는 7 x 8 크기의 Ascii 문자들로 이루어져 있습니다. c++11 과 c11 이상, linux, unix, windows 환경에서 사용할 수 있습니다. 
이전 Tetris 프로젝트에서 보이다 시피, 콘솔 프로그램에서 제목이나 강조하고 싶은 문구를 출력하는 것이 목적입니다. 지원하는 문자는 일반 Ascii code chracter 들 뿐입니다.
<br><br><br>

## puthdln

``` c
 size_t puthdln(const char* const str);
```
인자로 받은 문자열을 제목으로 stdout stream 으로 출력합니다. 출력한 문자열의 끝에는 자동으로 '\n' 가 따라옵니다. 다시 말해서, "1" 을 출력하게 되면 실제로 출력하는 것은 "1\n" 가 된다는 말입니다. 내부적으로 버퍼에 출력할 문자열들을 담았다가, 버퍼의 상한을 넘으면 flush 하는 로직으로 되어 있기에 해당 함수는 'atomic' 함을 항상 보장하지 않습니다.

### Parameters
str - nul-terminated multibyte string 을 가리키는 포인터.

### Return values
실제로 써진 bytes 의 갯수를 돌려줍니다. puthdln("1"); 을 호출하면, 56 x 2 = 112 를 돌려줍니다. 제목을 구성하는 문자 하나 당, 크기는 8 x 7 = 56 bytes 이지만. line 을 출력하는 것이기에 반환값에는 8 x 7 '\n' 의 크기도 포함되어 있습니다.

### Example
``` c
// example. using puthdln function.
# include"hdln.h"
# include<stdio.h>

int main()
{
    size_t written = puthdln("!\"#$%&'()*+,-./0\n"
                             "123456789:;<=>?@\n"
                             "ABCDEFGHIJKLMNOP\n"
                             "QRSTUVWXYZ[\\]^_`\n"
                             "abcdefghijklmnop\n"
                             "qrstuvwxyz{|}~");
                             
    printf("%zd", written);
}

```
``` text
  __      _  _             ||_            __       _      ___    ___                                                  _  _____         
 |  |    |_||_|  _//_//_  /  _]  _   __  (  )     |_|    / __|  |__ )     ____     _                                 / //  _  L        
 |  |            - -- -- /  |_  |_| / / ( O  )          / /        ) )   (_||_)  _| |_           _____              / / | / ) |        
 |  |           _//_//_  |_   |    / /  (_   )          ( |        | )   (_  _) |_   _|         |_____|            / /  | | | |        
 |__|           - -- --   _|| |   / /_   (  )_          ( |        | )   (_||_)   |_|    __                       / /   | | | |        
  __            // //    |_  _|  /_/|_| ( O | |         (  L_    __) )                  |_ |              _      / /    | |_/ /        
 |__|                      ||            (____|          L___|  |___)                     ||             |_|    /_/      L___/         
   _     _____   ___        /|     ___    ___   ______    ___     ___              __        _           _        ___     ____         
__| |   / __  ) /_  )      / |    /  _]  / __|  |     |  /   )   /    )    _      |__|      / /  _____   L L     (   |   ( __ )_       
|_  |   |_| / /  _|  )    /  |_  /  /_  / <__   | __  | (  O  ) ( O   )   |_|      __      / /  |_____|   L L   (_/| /  ( /  L//       
  | |      / /  [__  |   /  o  | |__  | |    )  |_| | |  >   <   L_   /    _      |_ |    / /    _____     L L   |-_/   (| 0  /)       
  | |     / /    _|  |  [___  _|    | | |  O  )     | | (  0  )    / /    |_|       ||   / /___ |_____|  ___L L  ||     ( L _/ )       
  | |    / /___ |    |      | |   __| | |     )     | | (     /   / /                   /______|        |_____>          (____)        
  |_|   (_____| |___/       |_|  |____|  L___/      |_|  L___/   /_/                                             []                    
 _____   _____    ___    ____     ___    _____    ____   _   _   _____   _____   __  __  _       _   _   ___   _ ______  ____          
/     | |     )  /  _]  |    )   /   _] |  ___]  /  __] | | | | |_   _| |_   _| |  |/ / | |     | |_| | |   ) /|/ ____ )|    )         
|  0  | |  0  ) /  |    |     ) /   |_  |  |__  /  /___ | |_| |   | |     | |   |  | /  | |     | | | | |  _ | |(/    ))| D   )        
|     | |    <  |  |    |  D  ) |    _] |  ___] |  |L | |  _  |   | |     | |   |   /_  | |___  |     | |  | | |(|    |)|   _)         
|  -  | |  0  ) |  |_   |     ) |   |_  |  |    |  |/ | | | | |   | |   __| |   |   _ L |     | | | | | |  | | |(|    |)|  |           
|  |  | |     ) |    |  |     ) |     | |  |    |     | | | | |  _| |_  ||| |   |  | ) ]|     | | |_| | |  |   |(L____/)|  |           
|__|__| |____/  |____|  |____/  |_____| |__|     L___/  |_| |_| |_____| L__/    |__| )_]|_____| |_| |_| |__|L__|L_____/ |__|           
 ______  ____     ____  _______  _   _   _   _   _   _   __  __  __  __  _____   ___    _        ___                    _              
/ ____ )|    )   / __ | |_   _| | | | | | | | | | |^| | [_|  | ][ |  | ][____ | |  _|   L|      |_  |     //LL          LL             
(/    ))| D   ) / /__||   | |   | | | | | | | | | | | |   LL_// [ L__| ]    / / | |      L|       | |    //  LL                        
(|   _|)|    )  L___  )   | |   | |_| | | |_| | |     |    | |   L    /    / /  | |       L|      | |                                  
(|  |||)| _ <    _  | |   | |   |     | |     | |  |  |  _/ _ L   |  |    / /   | |        L|     | |                                  
(|__/  || || )  | |_| |   | |   |     |  L   /  [  |  ] |  / | |  |  |   / /__  | |_        L|   _| |            ______                
(____/L||_||_|  |_____|   |_|   |_____|   [_/    L_|_/  |_|  L_|  |__|  [_____| |___|        L| |___|           |______|               
                                                                                                                                       
  ____   _        ___         _   ____     __     ____   _        _       _      _        _                              _  __         
 /___ ) | |      / __|       | | /    )   /__|   / O _| | |      |_|     |_|    | | _    | |     __ ___ ____     _____  | |/  )        
 ___/ | | |     /  |      __ | ||  O   )_/ |_   |___/   | |___    _     ____    | |/ /   | |    |/ | || | _ )   | ___ | |   O )        
/     | |  L__  |  |     /  L| || ____/ |   _|    //__  | /   )  | |    |__ |   |   /    | |    |     | | | |   ||   || |  __/         
| o   | |  D  ) |  |_   ( D    || |____  | |     / O  ) |  /| |  | |     _) |   | |) )   | L.   |  | || | | |   ||___|| | |            
|___/|| |____/  |____|   L___/|| L____/  |_|     |___/  |_| |_|  |_|    |__/    |_||_|   (__|   |__|_|| |_|_|   |_____| |_|            
                                                                                   __      __      __                  
 __ _    _       ___      _      _   _   _   _   _ ___   _   _   _   _   _____    / _|    |  |    |_ ]                 
(  V |  | |___  / __|   _| |_   | | | | | | | | | | | | | | | | | | | | |___  |  | /      |  |     _> >  ___           
( O  |  | / __| L L_    |_  _|  | | | | | | | | | | | | |_ V  / |_ V  |    / /   / _|     |  |    |_ <  / __|_//       
 L__ |  |  /     L_ L    | |    | |_| | |  V  | |     |  | _ |    L__ |   / /   < |_      |  |     _> > |/ |__/        
   | |  | |     ||_)|    | |_   |     | |_   _| |     | / / | |    _/ |  / /__   |_ |_    |  |    |  |                 
   |_|  |_|     |___/    |___|   L__/||   |_|    L|_|/  |_| |_|   |__/  /_____|   |__|    |__|    |_|                  
5600
```
<br><br><br>


## printhdln

``` c
 size_t printhdln(const char* RESTRICT fmt, ...);
```
fmt 에 명시된대로 내용을 해석한 결과를 제목으로, stdout stream 으로 출력합니다. 출력한 문자열의 끝에는 자동으로 '\n' 가 따라옵니다. 다시 말해서, "1" 을 출력하게 되면 실제로 출력하는 것은 "1\n" 가 된다는 말입니다. 내부적으로 버퍼에 출력할 문자열들을 담았다가, 버퍼의 상한을 넘으면 flush 하는 로직으로 되어 있기에 해당 함수는 'atomic' 함을 항상 보장하지 않습니다.

사용방법은 printf와 똑같으며, 그 결과는 vsnprintf 으로 만들어낸 결과와 같습니다. 그리고, 변환된 결과의 최대 크기는 2047 bytes 까지입니다. 2048 bytes 이상의 데이터들은 잘리게 되어 출력되지 않습니다. 내부적으로 동적할당과 해제는 일어나지는 않으며, 만약 변환하여 출력할 필요가 없다면 conversion 루틴을 거치지 않도록, puthdln 을 쓰는 것을 추천합니다.

### Parameters
fmt - 어떤식으로 해석할지의 내용을 포함한, null-terminated multibyte string 을 가리키는 포인터. <br>
&nbsp;&nbsp;&nbsp;... - fmt 문자열에서 명시한 서식문자에서 필요로하는 인자들. printf 와 사용법은 똑같습니다. 간략하게 요약하자면 아래와 같습니다:
  - ``` text
     Conversion Specifier
 
     []:optional, (): necessary


     %[flag][width][.precision][length](speicifier)

     flag      : -, +, (space), #, 0

     width     : integer value, *

     precision : .integer value,  .*

     length    : hh, h, (none), l, ll, j, z, t, L

     specifier : %, c, s, d, i, o, x, X, u, f, F, e, E, a, A, g, G, n, p 

인자의 갯수가 fmt 에 명시한 것보다 적거나, 각 서식문자가 기대한 타입의 인자가 아닌 경우 그 결과는 UB 입니다. 

### Return values
실제로 써진 bytes 의 갯수를 돌려줍니다. printhdln("1"); 을 호출하면, 56 x 2 = 112 를 돌려줍니다. 제목을 구성하는 문자 하나 당, 크기는 8 x 7 = 56 bytes 이지만. line 을 출력하는 것이기에 반환값에는 8 x 7 '\n' 의 크기도 포함되어 있습니다.

### Example
``` c
# include"hdln.h"
# include<time.h>

int main()
{  
    float PI        = 3.14159265358979323846264338327950288419716939937510582097f;
    const char*  s  = "Hello";
    size_t written  = printhdln("%.11s", "HELLO WORLD!!!");
    
    printhdln("bytesWritten: %zd", written);
    printhdln("\t.%10s.\n\t.%-10s.\n\t.%*s.", s, s, 10, s);
    printhdln("Floating point : %.10f\n"
              "Scientific     : %.10E\n", PI, PI);
}
```
``` text
 _   _    ___    _       _       ______          _   _   ______  ____    _       ____          
| | | |  /   _] | |     | |     / ____ )        | |^| | / ____ )|    )  | |     |    )         
| |_| | /   |_  | |     | |     (/    ))        | | | | (/    ))| D   ) | |     |     )        
|  _  | |    _] | |___  | |___  (|    |)        |     | (|    |)|    )  | |___  |  D  )        
| | | | |   |_  |     | |     | (|    |)        |  |  | (|    |)| _ <   |     | |     )        
| | | | |     | |     | |     | (L____/)        [  |  ] (L____/)| || )  |     | |     )        
|_| |_| |_____| |_____| |_____| L_____/          L_|_/  L_____/ |_||_|  |_____| |____/         
                                         _   _                                                                    ___   ______   _____         
 _       _   _    _       ____   ___    | |^| |  _        _       _       _       ____             _             / __|  |     | / __  )        
| |     | | | | _| |_    /    ) / __|   | | | | | |___   |_|    _| |_   _| |_    /    ) ____      |_|           / <__   | __  | |_| / /        
| |     |_ V  | |_  _|  |  O   )L L_    |     | | / __|   _     |_  _|  |_  _|  |  O   )| _ )      _            |    )  |_| | |    / /         
|  L__    L__ |  | |    | ____/  L_ L   |  |  | |  /     | |     | |     | |    | ____/ | | |     |_|           |  O  )     | |   / /          
|  D  )    _/ |  | |_   | |____ ||_)|   [  |  ] | |      | |     | |_    | |_   | |____ | | |                   |     )     | |  / /___        
|____/    |__/   |___|   L____/ |___/    L_|_/  |_|      |_|     |___|   |___|   L____/ |_|_|                    L___/      |_| (_____|        
       	                                                 _   _                                                 
       	                                                | | | |   ____    _       _                            
       	                                                | |_| |  /    )  | |     | |     _____                 
       	                                                |  _  | |  O   ) | |     | |    | ___ |                
       	                                                | | | | | ____/  | |     | |    ||   ||                
       	  _                                             | | | | | |____  | L.    | L.   ||___||   _            
       	 |_|                                            |_| |_|  L____/  (__|    (__|   |_____|  |_|           
       	         _   _                                                                                         
       	        | | | |   ____    _       _                                                                    
       	        | |_| |  /    )  | |     | |     _____                                                         
       	        |  _  | |  O   ) | |     | |    | ___ |                                                        
       	        | | | | | ____/  | |     | |    ||   ||                                                        
       	  _     | | | | | |____  | L.    | L.   ||___||                                           _            
       	 |_|    |_| |_|  L____/  (__|    (__|   |_____|                                          |_|           
       	                                                 _   _                                                 
       	                                                | | | |   ____    _       _                            
       	                                                | |_| |  /    )  | |     | |     _____                 
       	                                                |  _  | |  O   ) | |     | |    | ___ |                
       	                                                | | | | | ____/  | |     | |    ||   ||                
       	  _                                             | | | | | |____  | L.    | L.   ||___||   _            
       	 |_|                                            |_| |_|  L____/  (__|    (__|   |_____|  |_|           
 _____                                                                                                                                   ___               _        /|     _       ___    ___    _____  ______      /|     _     _____         
|  ___]   _               ____    _       _               ____           _  __            _               _                _            /_  )           __| |      / |  __| |     /  _]  /    ) / __  ) |     |    / |  __| |   /  _  L        
|  |__   | |     _____   /___ ) _| |_    |_|    ____     / O _|         | |/  )  _____   |_|    ____    _| |_             |_|            _|  )          |_  |     /  |_ |_  |    /  /_  ( O   ) |_| / / | __  |   /  |_ |_  |   | / ) |        
|  ___]  | |    | ___ |  ___/ | |_  _|    _     | _ )   |___/           |   O ) | ___ |   _     | _ )   |_  _|             _            [__  |            | |    /  o  |  | |    |__  |  L_   /    / /  |_| | |  /  o  |  | |   | | | |        
|  |     | |    ||   || /     |  | |     | |    | | |     //__          |  __/  ||   ||  | |    | | |    | |              |_|            _|  |            | |   [___  _|  | |       | |    / /    / /       | | [___  _|  | |   | | | |        
|  |     | L.   ||___|| | o   |  | |_    | |    | | |    / O  )         | |     ||___||  | |    | | |    | |_                           |    |    _       | |       | |   | |     __| |   / /    / /___     | |     | |   | |   | |_/ /        
|__|     (__|   |_____| |___/||  |___|   |_|    |_|_|    |___/          |_|     |_____|  |_|    |_|_|    |___|                          |___/    |_|      |_|       |_|   |_|    |____|  /_/    (_____|     |_|     |_|   |_|    L___/         
  ____                                                                                                                                   ___               _        /|     _       ___    ___    _____  ______      /|     _     _____    ___            _____   _____         
 / __ |   ___     _       ____            _       _        __     _       ___                                              _            /_  )           __| |      / |  __| |     /  _]  /    ) / __  ) |     |    / |  __| |   /  _  L  /   _]    _    /  _  L /  _  L        
/ /__||  / __|   |_|     /    ) ____    _| |_    |_|      /__|   |_|     / __|                                            |_|            _|  )          |_  |     /  |_ |_  |    /  /_  ( O   ) |_| / / | __  |   /  |_ |_  |   | / ) | /   |_   _| |_  | / ) | | / ) |        
L___  ) /  |      _     |  O   )| _ )   |_  _|    _     _/ |_     _     /  |                                               _            [__  |            | |    /  o  |  | |    |__  |  L_   /    / /  |_| | |  /  o  |  | |   | | | | |    _] |_   _| | | | | | | | |        
 _  | | |  |     | |    | ____/ | | |    | |     | |    |   _|   | |    |  |                                              |_|            _|  |            | |   [___  _|  | |       | |    / /    / /       | | [___  _|  | |   | | | | |   |_    |_|   | | | | | | | |        
| |_| | |  |_    | |    | |____ | | |    | |_    | |     | |     | |    |  |_                                                           |    |    _       | |       | |   | |     __| |   / /    / /___     | |     | |   | |   | |_/ / |     |         | |_/ / | |_/ /        
|_____| |____|   |_|     L____/ |_|_|    |___|   |_|     |_|     |_|    |____|                                                          |___/    |_|      |_|       |_|   |_|    |____|  /_/    (_____|     |_|     |_|   |_|    L___/  |_____|          L___/   L___/         
       
       
       
       
       
       
       

```
