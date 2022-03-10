#include <stdio.h>

int main()
{
    char c[4] = {'B', 'A', 'E', 0}; // 빈공간이 있어야 문자열 끝임을 알 수 있다.
    char d[] = "hello";
    printf("%s %s", c, d);
} 