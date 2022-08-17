# hdln.c
write headline string to stdout stream

함수로 전달한 문자열을  바꾸어 stdout stream 으로 출력합니다. 



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
