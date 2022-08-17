# hdln.c
write a headline string to stdout stream

문자열을 제목으로 바꾸어 출력합니다. 각 문자는 7 x 8 크기의 아스키 문자들로 



## puthdln
``` c
int puthdln(const char* const str);
```


``` c
// example 1. using puthdln function.
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
