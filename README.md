# hdln.c
write headline string to stdout stream


``` c
// example 1.
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
