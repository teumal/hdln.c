# hdln.c
write a headline string to stdout stream

문자열을 제목으로 바꾸어 출력합니다. 각 문자는 7 x 8 크기의 Ascii 문자들로 이루어져 있습니다. c++11 과 c11 이상, linux, unix, windows 환경에서 사용할 수 있습니다. 
이전 Tetris 프로젝트에서 보이다 시피, 콘솔 프로그램에서 제목이나 강조하고 싶은 문구를 출력하는 것이 목적입니다. 지원하는 문자는 일반 Ascii code chracter 들 뿐입니다.

아스키 아트를 변경하고 싶다면, puthdln 함수 내에 있는 data 배열을 수정하면 됩니다. 단, 각 문자별 아스키 아트의 크기는 항상 7 x 8 (row x col) 이어야 합니다( col 에 NUL 문자를 고려할 필요는 없습니다.). data의 한 행의 크기는 sizeof(int64_t) * 128 이며, 각 문자의 데이터가 8 bytes 씩 연속적으로 배열되어 있습니다. 이는 각 행을 처리하는 동안  data caching 효율을 높여줍니다. 64 bit 모드에서 사용하는 것을 추천합니다.

아스키 코드의 일부 특수 문자('\n', '\t' 제외)의 경우, 공백만이 출력되는데 이는 자주 쓰는 아스키 코드 문자만을 출력하고자 만든 라이브러리이기 때문입니다. hdln 은 chracter string 을 headline 으로 바꿔서 출력하는 두 개의 함수 puthdln(put headline), printhdln(print headline) 를 제공합니다:

<br><br><br>

## puthdln

``` c
 size_t puthdln(const char* const str);
```
인자로 받은 문자열을 제목으로 stdout stream 으로 출력합니다. 출력한 문자열의 끝에는 자동으로 '\n' 가 따라옵니다. 다시 말해서, "1" 을 출력하게 되면 실제로 출력하는 것은 "1\n" 가 된다는 말입니다. 내부적으로 버퍼에 출력할 문자열들을 담았다가, 버퍼의 상한을 넘으면 flush 하는 로직으로 되어 있기에 해당 함수는 'atomic' 함을 항상 보장하지 않습니다. 전달한 문자열을 구성하는 문자가 0~127 사이의 ascii code character 가 아닐 경우, 결과는 undefined behavior 입니다.

### Parameters
str - null-terminated multibyte string 을 가리키는 포인터.

### Return values
실제로 써진 bytes 의 갯수를 돌려줍니다. puthdln("1"); 을 호출하면, 56 x 2 = 112 를 돌려줍니다. 제목을 구성하는 문자 하나 당, 크기는 8 x 7 = 56 bytes 이지만. line 을 출력하는 것이기에 반환값에는 8 x 7 '\n' 의 크기도 포함되어 있습니다.

### Example
``` c
// example. using puthdln function.
# include"hdln.h"  // printhdln, printf

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
fmt 에 명시된대로 내용을 해석한 결과를 제목으로, stdout stream 으로 출력합니다. 출력한 문자열의 끝에는 자동으로 '\n' 가 따라옵니다. 다시 말해서, "1" 을 출력하게 되면 실제로 출력하는 것은 "1\n" 가 된다는 말입니다. 내부적으로 버퍼에 출력할 문자열들을 담았다가, 버퍼의 상한을 넘으면 flush 하는 로직으로 되어 있기에 해당 함수는 'atomic' 함을 항상 보장하지 않습니다. 전달한 문자열을 구성하는 문자가 0~127 사이의 ascii code character 가 아닐 경우, 결과는 undefined behavior 입니다.

사용방법은 printf와 똑같으며, 그 결과는 vsnprintf 으로 만들어낸 결과와 같습니다. 그리고, 변환된 결과의 최대 크기는 2047 bytes 까지입니다. 2048 bytes 이상의 데이터들은 잘리게 되어 출력되지 않습니다. 만약 변환하여 출력할 필요가 없다면 conversion 루틴을 거치지 않도록, puthdln 을 쓰는 것을 추천합니다. 

### Parameters
fmt - 어떤식으로 해석할지의 내용을 포함한, null-terminated multibyte string 을 가리키는 포인터. printf 와 사용법은 똑같습니다. 간략하게 요약하자면 아래와 같습니다:
  - ``` text
     Conversion Specifier
 
     []:optional, (): necessary


     %[flag][width][.precision][length](speicifier)

     flag      : -, +, (space), #, 0

     width     : integer value, *

     precision : .integer value,  .*

     length    : hh, h, (none), l, ll, j, z, t, L

     specifier : %, c, s, d, i, o, x, X, u, f, F, e, E, a, A, g, G, n, p
&nbsp;&nbsp;&nbsp;... - fmt 문자열에서 명시한 서식문자에서 필요로하는 인자들. 인자의 갯수가 fmt 에 명시한 것보다 적거나, 각 서식문자가 기대한 타입의 인자가 아닌 경우 그 결과는 UB 입니다. 

### Return values
실제로 써진 bytes 의 갯수를 돌려줍니다. printhdln("1"); 을 호출하면, 56 x 2 = 112 를 돌려줍니다. 제목을 구성하는 문자 하나 당, 크기는 8 x 7 = 56 bytes 이지만. line 을 출력하는 것이기에 반환값에는 8 x 7 '\n' 의 크기도 포함되어 있습니다.

### Example
``` c
// Example 1. 
# include"hdln.h"
# define PI 3.14159265358979323846264338327950288419716939937510582097f

int main()
{  
    size_t written  = printhdln("%.11s", "HELLO WORLD!!!");
    const char*  s  = "Hello";
    
    printhdln("bytesWritten: %zd", written);
    printhdln("\t.%10s.\n"
              "\t.%-10s.\n"
              "\t.%*s.",   s, s, 10, s);
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

<br><br><br>

``` c++
// Example 2. make a digital clock with printhdln
# include"hdln.h"  // printhdln
# include<thread>  // std::this_thread::sleep_for, std::chrono::seconds
# include<ctime>   // tm, time_t, time, localtime
# include<cstdlib> // system

int main()
{
    time_t timer;
    tm*    cur;
    
    while(true) {
      time(&timer);
      cur = localtime(&timer);
      
      printhdln("%02d:%02d:%02d", 
                cur->tm_hour, 
                cur->tm_min,
                cur->tm_sec );
                
      std::this_thread::sleep_for(std::chrono::seconds(1) );  
      system("clear"); // execute unix command "clear"
                       // in Windows, use system("cls") instead.
    }
}
```
<img src='https://github.com/teumal/hdln.c/blob/main/digital_clock.gif?raw=true'>

