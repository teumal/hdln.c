# hdln.c
write a headline string to stdout stream

문자열을 제목으로 바꾸어 출력합니다. 각 문자는 7 x 8 크기의 Ascii 문자들로 이루어져 있습니다. c++11 과 c11 이상, linux, unix, windows 환경에서 사용할 수 있습니다. 
이전 Tetris 프로젝트에서 보이다 시피, 콘솔 프로그램에서 제목이나 강조하고 싶은 문구를 출력하는 것이 목적입니다. 지원하는 문자는 일반 Ascii code chracter 들 뿐입니다.

todo list
- [ ] size_t printhdln(const char* restrict fmt, ...); 함수 추가. 사용법은 printf 와 똑같을 예정.

<br><br><br>


### puthdln
______________________________________
``` c
 puthdln(const char* const str);
```
인자로 받은 문자열을 제목으로 stdout stream 으로 출력합니다. 출력한 문자열의 끝에는 자동으로 '\n' 가 따라옵니다. 다시 말해서, "1" 을 출력하게 되면 실제로 출력하는 것은 "1\n" 가 된다는 말입니다. 내부적으로 버퍼에 출력할 문자열들을 담았다가, 버퍼의 상한을 넘으면 flush 하는 로직으로 되어 있기에 해당 함수는 thread-safe 함을 항상 보장하지 않습니다.

### Parameters
str - 제목으로 출력할 character string.

### Return values
실제로 써진 bytes 의 갯수를 돌려줍니다. printhdln("1"); 을 호출하면, 56 x 2 = 112 를 돌려줍니다. 제목을 구성하는 문자 하나 당, 크기는 8 x 7 = 56 bytes 이지만. line 을 출력하는 것이기에 마지막에 8 x 7 크기의 '\n' 도 출력합니다.

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
<img src='https://github.com/teumal/hdln.c/blob/main/output.JPG?raw=true'>
